#pragma once

#include <bits/stdc++.h>

struct DSU {
    std::vector<int> p, siz;
    DSU(int n = 0) : p(n), siz(n, 1) { std::iota(p.begin(), p.end(), 0); }
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        siz[x] += siz[y];
        p[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};