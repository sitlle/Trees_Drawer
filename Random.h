#include<bits/stdc++.h>
#pragma once

static int64_t get_random() {
    static std::mt19937 rnd(52);
    return static_cast<int64_t>(rnd());
}