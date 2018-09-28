/**
 * Copyright 2018-present Antonio Mallia
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

static_assert(__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__,
              "bit_vector.hpp requires little endian architectures");

namespace detail {
template <typename IntType1, typename IntType2>
inline IntType1 ceil_div(IntType1 dividend, IntType2 divisor) {
    // XXX(ot): put some static check that IntType1 >= IntType2
    IntType1 d = IntType1(divisor);
    return IntType1(dividend + d - 1) / d;
}
inline size_t words_for(uint64_t n) { return ceil_div(n, 64); }
} // namespace detail

namespace bv {

class bit_vector {

   private:
    class reference {
       public:
        reference(bit_vector &bv, size_t pos) noexcept : m_bv(bv), m_pos(pos) {}

        operator bool() const noexcept { return m_bv.test(m_pos); }

        reference &operator=(bool b) noexcept {
            m_bv.set(m_pos, b);
            return *this;
        }

        reference &operator=(const reference &other) noexcept {
            m_bv.set(m_pos, bool(other));
            return *this;
        }

       private:
        bit_vector &m_bv;
        size_t      m_pos;
    };

    class const_iterator {

       public:
        const_iterator(const bit_vector &bv, size_t pos = 0) : m_bv(bv), m_pos(pos) {}

        const_iterator operator++() {
            m_pos += 1;
            return *this;
        }

        const_iterator operator++(int count) {
            m_pos += count;
            return *this;
        }

        bool operator*() { return m_bv.test(m_pos); }

        bool operator->() { return m_bv.test(m_pos); }

        bool operator==(const const_iterator &other) const {
            return (m_pos == other.m_pos) and (m_bv == other.m_bv);
        }
        bool operator!=(const const_iterator &other) const { return !(*this == other); }

       private:
        const bit_vector &m_bv;
        size_t            m_pos;
    };

    class iterator {

       public:
        iterator(bit_vector &bv, size_t pos = 0) : m_bv(bv), m_pos(pos) {}

        iterator operator++() {
            m_pos += 1;
            return *this;
        }

        iterator operator++(int count) {
            m_pos += count;
            return *this;
        }

        reference operator*() { return reference{m_bv, m_pos}; }

        reference operator->() { return reference{m_bv, m_pos}; }

        bool operator==(const iterator &other) const {
            return (m_pos == other.m_pos) and (m_bv == other.m_bv);
        }
        bool operator!=(const iterator &other) const { return !(*this == other); }

       private:
        bit_vector &m_bv;
        size_t            m_pos;
    };


    inline bool test(uint64_t pos) const {
        assert(pos < m_size);
        uint64_t block = pos / 64;
        assert(block < m_bits.size());
        uint64_t shift = pos % 64;
        return (m_bits[block] >> shift) & 1;
    }

    inline void set(uint64_t pos, bool b) {
        uint64_t word        = pos / 64;
        uint64_t pos_in_word = pos % 64;
        m_bits[word] &= ~(uint64_t(1) << pos_in_word);
        m_bits[word] |= uint64_t(b) << pos_in_word;
    }

   public:
    bit_vector() = default;
    explicit bit_vector(size_t count, bool value = false) : m_size(count) {
        m_bits.resize(detail::words_for(count), uint64_t(-value));
        if (count) {
            auto &cur_word = m_bits.back();
            auto  p        = count % 64;
            if (value && p) {
                cur_word >>= 64 - p;
            }
        }
    }

    bit_vector(const bit_vector &other) {
        m_bits = other.m_bits;
        m_size = other.m_size;
    }

    bit_vector(bit_vector &&other) noexcept {
        m_bits = std::move(other.m_bits);
        m_size = other.m_size;
    }

    bit_vector &operator=(bit_vector const &other) {
        m_bits = other.m_bits;
        m_size = other.m_size;
        return *this;
    }

    bit_vector &operator=(bit_vector &&other) {
        m_bits = std::move(other.m_bits);
        m_size = other.m_size;
        return *this;
    }

    inline void reserve(size_t new_cap) { m_bits.reserve(detail::words_for(new_cap)); }

    inline void resize(size_t count) { m_bits.resize(count); }

    inline void clear() noexcept {
        m_bits.clear();
        m_size = 0;
    }

    inline void push_back(bool b) {
        size_t pos_in_word = m_size % 64;
        if (pos_in_word == 0) {
            m_bits.push_back(0);
        }
        auto &cur_word = m_bits.back();
        cur_word |= (uint64_t)b << pos_in_word;
        m_size += 1;
    }

    inline bool operator[](size_t pos) const { return test(pos); }

    inline reference operator[](size_t pos) { return reference{*this, pos}; }

    inline void set() { std::fill(m_bits.begin(), m_bits.end(), uint64_t(-1)); }

    inline size_t size() const noexcept { return m_size; }

    inline bool empty() const noexcept { return m_size == 0; }

    const_iterator begin() const noexcept { return const_iterator(*this); }

    const_iterator end() const noexcept { return const_iterator(*this, m_size); }

    iterator begin() noexcept { return iterator(*this); }

    iterator end() noexcept { return iterator(*this, m_size); }

    const uint64_t *data() const noexcept { return m_bits.data(); }

    bool operator==(const bit_vector &other) const {
        return (m_size == other.m_size) and (m_bits == other.m_bits);
    }
    bool operator!=(const bit_vector &other) const { return !(*this == other); }
    void swap(bit_vector &other) noexcept {
        using std::swap;
        swap(m_bits, other.m_bits);
        swap(m_size, other.m_size);
    }

   private:
    std::vector<uint64_t> m_bits;
    size_t                m_size = 0;
};
} // namespace bv