static constexpr int N = 1 << 18; // enough for n ≤ 1e5 (2 * 2^17)

struct Node {
    int len = 0;
    int longest = 0;
    int pref = 0;
    int suff = 0;
    char left = 0;
    char right = 0;

    Node() = default;
    Node(int len, int longest, int pref, int suff, char left, char right)
        : len(len), longest(longest), pref(pref), suff(suff), left(left), right(right) {}
};

inline Node merge(Node& L, Node& R) {
    int len = L.len + R.len;
    int longest = max(L.longest, R.longest);

    bool canJoin = (L.right == R.left);
    if (canJoin)
        longest = max(longest, L.suff + R.pref);

    int pref = L.pref;
    if (L.pref == L.len && canJoin)
        pref += R.pref;

    int suff = R.suff;
    if (R.suff == R.len && canJoin)
        suff += L.suff;

    return Node(len, longest, pref, suff, L.left, R.right);
}

Node tree[N];

class SegTree {
public:
    unsigned n, n2;

    SegTree(string& s) : n(s.size()) {
        n2 = bit_ceil(n);

        // clear the whole tree
        for (int i = 0; i < (n2 << 1); ++i)
            tree[i] = Node();

        // build leaves
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            tree[i + n2] = Node(1, 1, 1, 1, c, c);
        }

        // build internal nodes bottom-up
        for (int i = n2 - 1; i >= 1; --i)
            tree[i] = merge(tree[i << 1], tree[(i << 1) | 1]);
    }

    void update(int idx, char c) {
        idx += n2;
        tree[idx] = Node(1, 1, 1, 1, c, c);

        for (idx >>= 1; idx >= 1; idx >>= 1)
            tree[idx] = merge(tree[idx << 1], tree[(idx << 1) | 1]);
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegTree seg(s);
        int k = queryIndices.size();
        vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            seg.update(queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].longest;   // root always holds the global answer
        }
        return ans;
    }
};