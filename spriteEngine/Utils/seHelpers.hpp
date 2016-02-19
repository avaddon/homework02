//
//  seHelpers.hpp
//  spriteEngine
//
//  Created by Domrachev Alexandr on 27.01.16.
//  Copyright © 2016 Domrachev Alexandr. All rights reserved.
//

#ifndef seHelpers_h
#define seHelpers_h

#include <string>
#include <sstream>
#include <numeric>
#include <vector>
#include <glm/glm.hpp>

namespace spriteEngine {
    inline std::string quoteStr(const std::string &str) {
        return "'" + str + "'";
    }

    inline bool ends_with(std::string const &value, std::string const &ending) {
        if (ending.size() > value.size())
            return false;
        return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
    }

    inline std::string ReplaceString(std::string subject, const std::string& search, const std::string& replace) {
        size_t pos = 0;
        while ((pos = subject.find(search, pos)) != std::string::npos) {
            subject.replace(pos, search.length(), replace);
            pos += replace.length();
        }
        return subject;
    }

    template<typename T>
    inline std::vector<T> inc_fill_vector(T count) {
        std::vector<T> vec(count);
        std::iota(std::begin(vec), std::end(vec), 0);
        return vec;
    }

    template<typename T>
    std::string to_string(const T &n) {
        std::ostringstream stm;
        stm << n;
        return stm.str();
    }
}

#endif /* seHelpers_h */
