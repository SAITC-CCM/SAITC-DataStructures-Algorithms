#include "skew.h"

void printVector(std::vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

inline bool SuffixArraySkew::leq(int a1, int a2, int b1, int b2)
{
    return (a1 < b1 || (a1 == b1 && a2 <= b2));
}

inline bool SuffixArraySkew::leq(int a1, int a2, int a3, int b1, int b2, int b3)
{
    return (a1 < b1 || (a1 == b1 && leq(a2, a3, b2, b3)));
}

SuffixArraySkew::SuffixArraySkew(std::string text)
{
    this->text = std::vector<int>(text.begin(), text.end());
    suffixArray.resize(this->text.size());
    ALPHABET_SIZE = *std::max_element(this->text.begin(), this->text.end()) + 1;
    skew(this->text, suffixArray, this->text.size(), ALPHABET_SIZE);
}

void SuffixArraySkew::print()
{
    for (int i = 0; i < suffixArray.size(); i++)
    {
        std::cout << suffixArray[i] << " ";
    }
    std::cout << std::endl;
}

void SuffixArraySkew::radixPass(std::vector<int> &A, std::vector<int> &B, std::vector<int> &text, int offset, int n, int K)
{
    std::vector<int> count(K + 1, 0);
    for (int i = 0; i < n; i++)
    {
        count[text[A[i] + offset]]++;
    }
    for (int i = 0, sum = 0; i <= K; i++)
    {
        int t = count[i];
        count[i] = sum;
        sum += t;
    }
    for (int i = 0; i < n; i++)
    {
        B[count[text[A[i] + offset]]++] = A[i];
    }
}

void SuffixArraySkew::skew(std::vector<int> &text, std::vector<int> &sa, int n, int k){
    // Construct the sample
    int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;

    std::vector<int> ranks(n02 + 3, 0);
    std::vector<int> sa12(n02 + 3, 0);
    std::vector<int> ranks0(n0, 0);
    std::vector<int> sa0(n0, 0);

    // Add sentinel
    text.push_back(0);
    text.push_back(0);
    text.push_back(0);

    // Generate positions of mod 1 and mod 2 suffixes
    // The "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
    for (int i = 0, j = 0; i < n + (n0 - n1); i++)
    {
        if (i % 3 != 0)
        {
            ranks[j++] = i;
        }
    }

    // Radix sort the mod 1 and mod 2 triples
    radixPass(ranks, sa12, text, 2, n02, k);
    radixPass(sa12, ranks, text, 1, n02, k);
    radixPass(ranks, sa12, text, 0, n02, k);

    // Find lexicographic names of triples
    int name = 0, c0 = -1, c1 = -1, c2 = -1;
    for (int i = 0; i < n02; i++)
    {
        if (text[sa12[i]] != c0 || text[sa12[i] + 1] != c1 || text[sa12[i] + 2] != c2)
        {
            name++;
            c0 = text[sa12[i]];
            c1 = text[sa12[i] + 1];
            c2 = text[sa12[i] + 2];
        }
        if (sa12[i] % 3 == 1)
        {
            ranks[sa12[i] / 3] = name;
        }
        else
        {
            ranks[sa12[i] / 3 + n0] = name;
        }
    }

    // Recurse if names are not yet unique
    if (name < n02)
    {
        skew(ranks, sa12, n02, name);
        for (int i = 0; i < n02; i++)
        {
            ranks[sa12[i]] = i + 1;
        }
    }
    else
    {
        for (int i = 0; i < n02; i++)
        {
            sa12[ranks[i] - 1] = i;
        }
    }

    // Store unique names in R using the suffix array
    for (int i = 0, j = 0; i < n02; i++)
    {
        if (sa12[i] < n0)
        {
            ranks0[j++] = 3 * sa12[i];
        }
    }
    radixPass(ranks0, sa0, text, 0, n0, k);

    suffixArray.resize(n);
    // Merge sorted SA0 suffixes and sorted SA12 suffixes
    for (int p = 0, t = n0 - n1, k = 0; k < n; k++)
    {
        int i = (sa12[t] < n0 ? sa12[t] * 3 + 1 : (sa12[t] - n0) * 3 + 2);
        int j = sa0[p];
        if (sa12[t] < n0 ? leq(text[i], ranks[sa12[t] + n0], text[j], ranks[j / 3])
                         : leq(text[i], text[i + 1], ranks[sa12[t] - n0 + 1], text[j], text[j + 1], ranks[j / 3 + n0]))
        {
            sa[k] = i;
            t++;
            if (t == n02)
            {
                for (k++; p < n0; p++, k++)
                {
                    sa[k] = sa0[p];
                }
            }
        }
        else
        {
            sa[k] = j;
            p++;
            if (p == n0)
            {
                for (k++; t < n02; t++, k++)
                {
                    sa[k] = (sa12[t] < n0 ? sa12[t] * 3 + 1 : (sa12[t] - n0) * 3 + 2);
                }
            }
        }
    }
}