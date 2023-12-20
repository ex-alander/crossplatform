#include <iostream>
#include <string>
#include <vector>
const int ALPHABET_SIZE = 256;
void badCharHeuristic(std::string str, int size, int badchar[ALPHABET_SIZE]) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        badchar[i] = -1;
    }
    for (int i = 0; i < size; i++) {
        badchar[(int)str[i]] = i;
    }
}

void searchBoyerMoore(std::string txt, std::string pat) {
    int m = pat.size();
    int n = txt.size();

    int badchar[ALPHABET_SIZE];
    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j]) {
            j--;
        }
        if (j < 0) {
            std::cout << "Pattern occurs at shift " << s << std::endl;
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }
        else {
            s += std::max(1, j - badchar[txt[s + j]]);
        }
    }
}

void computeLPSArray(std::string pat, std::vector<int>& lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(std::string txt, std::string pat) {
    std::vector<int> lps(pat.size());
    computeLPSArray(pat, lps);
    int n = txt.size();
    int m = pat.size();
    int i = 0;
    int j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == m) {
            std::cout << "Pattern occurs at shift " << i - j << std::endl;
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i = i + 1;
            }
        }
    }
}

void searchRabinKarp(std::string txt, std::string pat) {
    int d = 256; // размер алфавита
    int q = 101; // простое число

    int n = txt.size();
    int m = pat.size();
    int i, j;
    int p = 0; // хеш для шаблона
    int t = 0; // хеш для текста
    int h = 1;

    // вычисляем значение h: h = d^(m-1) % q
    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // вычисляем хеш для шаблона и первое окно текста
    for (i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // скользим по тексту
    for (i = 0; i <= n - m; i++) {
        // если хеши совпадают, проверяем посимвольно
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
            if (j == m) {
                std::cout << "Pattern occurs at shift " << i << std::endl;
            }
        }
        // вычисляем хеш для следующего окна текста
        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0) {
                t = (t + q);
            }
        }
    }
}

void searchShiftOr(std::string txt, std::string pat) {
    int m = pat.size();
    int n = txt.size();

    std::vector<int> mask(256, 0);
    for (int i = 0; i < m; i++) {
        mask[pat[i]] |= 1 << i;
    }

    int state = 0;
    for (int i = 0; i < n; i++) {
        state = ((state << 1) | 1) & mask[txt[i]];
        if (state & (1 << (m - 1))) {
            std::cout << "Pattern occurs at shift " << (i - m + 1) << std::endl;
        }
    }
}

void searchNaive(std::string txt, std::string pat) {
    int m = pat.size();
    int n = txt.size();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (txt[i + j] != pat[j]) {
                break;
            }
        }
        if (j == m) {
            std::cout << "Pattern occurs at shift " << i << std::endl;
        }
    }
}
