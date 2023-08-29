#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    
    int numberOfReports, finish, start;
    cin >> numberOfReports;
    vector<int> indexes;
    vector<int> maxIndexes;
    vector<pair<pair<int, int>, int> > finishAndStart;
    for (size_t i = 0; i < numberOfReports; ++i) {
        cin >> start >> finish;
        finishAndStart.push_back(make_pair(make_pair(start, finish), i+1));
    }
    sort(finishAndStart.begin(), finishAndStart.end());
    for (size_t i = 0; i < finishAndStart.size(); ++i) {
        indexes.push_back(finishAndStart[i].second);
        for(size_t j = 1; j < finishAndStart.size(); ++j) {
            if(finishAndStart[i].first.second <= finishAndStart[j].first.first) {
               i = j;
               indexes.push_back(finishAndStart[i].second);
            }
        } 
        if (indexes.size() > maxIndexes.size()) {
            maxIndexes = indexes;
            indexes.clear();
        }
    }
    for(size_t i = 0; i < maxIndexes.size(); ++i) {
        cout << maxIndexes[i] << " ";
    }
}
