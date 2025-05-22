#include <bits/stdc++.h>


void generateMapping() {
    int sizeLimit, fixedPoint;
    std::cin >> sizeLimit >> fixedPoint;

    std::vector<int> output(sizeLimit + 1, 0);
    std::vector<bool> valueUsed(sizeLimit + 1, false);
    std::vector<bool> indexFilled(sizeLimit + 1, false);

    if (fixedPoint >= 1 && fixedPoint <= sizeLimit) {
        output[fixedPoint] = fixedPoint;
        valueUsed[fixedPoint] = true;
        indexFilled[fixedPoint] = true;
    }

    for (int pos = 1; pos <= sizeLimit; ++pos) {
        if (indexFilled[pos] || valueUsed[pos]) {
            continue;
        }

        if ((pos | fixedPoint) != fixedPoint) {
            continue;
        }

        int partner = fixedPoint & (~pos);

        if (partner == 0 || partner == pos) {
            continue;
        }

        if (partner >= 1 && partner <= sizeLimit && !indexFilled[partner] && !valueUsed[partner]) {
            output[pos] = partner;
            output[partner] = pos;

            valueUsed[pos] = true;
            valueUsed[partner] = true;
            indexFilled[pos] = true;
            indexFilled[partner] = true;
        }
    }

    std::vector<int> openIndexes, unusedNumbers;

    for (int itr = 1; itr <= sizeLimit; ++itr) {
        if (!indexFilled[itr]) {
            openIndexes.push_back(itr);
        }
        if (!valueUsed[itr]) {
            unusedNumbers.push_back(itr);
        }
    }

    for (size_t i = 0; i < openIndexes.size(); ++i) {
        output[openIndexes[i]] = unusedNumbers[i];
    }

    for (int i = 1; i <= sizeLimit; ++i) {
        std::cout << output[i] << (i == sizeLimit ? "\n" : " ");
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        generateMapping();
    }
    return 0;
}