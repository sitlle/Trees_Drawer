#include<bits/stdc++.h>
#pragma once

static int64_t get_random() {
    static std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    return static_cast<int64_t>(rnd());
}