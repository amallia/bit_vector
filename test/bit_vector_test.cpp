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
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "bit_vector/bit_vector.hpp"

inline std::vector<bool> random_bit_vector(size_t n = 10000, double density = 0.5) {
    std::vector<bool> v;
    for (size_t i = 0; i < n; ++i) {
        v.push_back(rand() < (RAND_MAX * density));
    }
    return v;
}

TEST(bit_vector_test, empty) {

    bv::bit_vector vector;
    EXPECT_EQ(vector.size(), 0);
    EXPECT_TRUE(vector.empty());
}

TEST(bit_vector_test, initialized) {

    bv::bit_vector vector(10, true);
    EXPECT_EQ(vector.size(), 10);
    EXPECT_FALSE(vector.empty());
    for (size_t i = 0; i < 10; ++i) {
        EXPECT_EQ(vector[i], true);
    }
}

TEST(bit_vector_test, push_back) {

    bv::bit_vector vector;
    vector.push_back(true);

    EXPECT_EQ(vector.size(), 1);
    EXPECT_FALSE(vector.empty());
    EXPECT_EQ(vector[0], true);
}

TEST(bit_vector_test, swap) {
    bv::bit_vector vector1(10, true);
    bv::bit_vector vector2(5, false);
    vector1.swap(vector2);

    EXPECT_EQ(vector1.size(), 5);
    EXPECT_EQ(vector2.size(), 10);

    for (size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(vector1[i], false);
    }

    for (size_t i = 0; i < 10; ++i) {
        EXPECT_EQ(vector2[i], true);
    }

}

TEST(bit_vector_test, copy_constructor) {
    {
        bv::bit_vector vector1(10, true);
        bv::bit_vector vector2(vector1);
        EXPECT_EQ(vector2.size(), 10);
        for (size_t i = 0; i < 10; ++i) {
            EXPECT_EQ(vector2[i], true);
        }
    }
    {
        bv::bit_vector vector1(10, true);
        bv::bit_vector vector2(std::move(vector1));
        EXPECT_EQ(vector2.size(), 10);
        for (size_t i = 0; i < 10; ++i) {
            EXPECT_EQ(vector2[i], true);
        }
    }
    {
        bv::bit_vector vector1(10, true);
        bv::bit_vector vector2 = vector1;
        EXPECT_EQ(vector2.size(), 10);
        for (size_t i = 0; i < 10; ++i) {
            EXPECT_EQ(vector2[i], true);
        }
    }
    {
        bv::bit_vector vector1(10, true);
        bv::bit_vector vector2 = std::move(vector1);
        EXPECT_EQ(vector2.size(), 10);
        for (size_t i = 0; i < 10; ++i) {
            EXPECT_EQ(vector2[i], true);
        }
    }
}

TEST(bit_vector_test, set) {

    {
        bv::bit_vector vector(10);
        for (size_t i = 0; i < 10; ++i) {
            EXPECT_EQ(vector[i], false);
        }
        vector.set();
        for (size_t i = 0; i < 10; ++i) {
            EXPECT_EQ(vector[i], true);
        }
    }
    {
        bv::bit_vector vector(10);
        for (size_t i = 0; i < 10; ++i) {
            EXPECT_EQ(vector[i], false);
        }
        vector[5] = true;
        for (size_t i = 0; i < 10; ++i) {
            if(i == 5)
                EXPECT_EQ(vector[i], true);
            else
                EXPECT_EQ(vector[i], false);
        }
    }
    {
        bv::bit_vector vector(10, true);
        for (size_t i = 0; i < 10; ++i) {
            EXPECT_EQ(vector[i], true);
        }
        vector[5] = false;
        for (size_t i = 0; i < 10; ++i) {
            if(i == 5)
                EXPECT_EQ(vector[i], false);
            else
                EXPECT_EQ(vector[i], true);
        }
    }
    {
        bv::bit_vector vector(10, true);
        for (size_t i = 0; i < 10; ++i) {
            EXPECT_EQ(vector[i], true);
        }
        vector[5] = !vector[0];
        for (size_t i = 0; i < 10; ++i) {
            if(i == 5)
                EXPECT_EQ(vector[i], false);
            else
                EXPECT_EQ(vector[i], true);
        }
    }
}

TEST(bit_vector_test, iterator) {

    {
        bv::bit_vector vector(10);
        auto it = vector.begin();
        EXPECT_EQ(*it, false);

        vector[1] = true;
        ++it;
        EXPECT_EQ(*it, true);
    }
    {
        bv::bit_vector vector(10, true);
        for (auto it = vector.begin(); it != vector.end(); ++it)
        {
            EXPECT_EQ(*it, true);
        }
        for(auto&& v : vector) {
            EXPECT_EQ(v, true);
        }
    }
    {
        bv::bit_vector vector(10, true);
        for (auto it = vector.begin(); it != vector.end(); ++it)
        {
            *it = false;
        }
        for(auto&& v : vector) {
            EXPECT_EQ(v, false);
        }
    }
}

TEST(bit_vector_test, fuzzy) {

    auto v = random_bit_vector();

    {
        bv::bit_vector vector;
        for (size_t i = 0; i < v.size(); ++i) {
            vector.push_back(v[i]);
        }

        for (size_t i = 0; i < v.size(); ++i) {
            EXPECT_EQ(vector[i], v[i]);
        }

    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
