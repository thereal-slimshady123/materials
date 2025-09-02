#include <bits/stdc++.h>
using namespace std;

int comparex(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

int comparey(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

float dist(const pair<int, int> &a, const pair<int, int> &b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

pair<pair<int,int>,pair<int,int>> closestsplitpair(vector<pair<int, int>> &points_y, float min_dist, pair<int, int> mid_point){
    vector<pair<int,int>> strip;
    for (const auto &point : points_y) {
        if (abs(point.first - mid_point.first) < min_dist) {
            strip.push_back(point);
        }
    }
    pair<pair<int,int>,pair<int,int>> closest_pair={{INT_MAX, INT_MAX}, {INT_MAX, INT_MAX}};
    float min_strip_dist = FLT_MAX;
    for(int i=0;i<strip.size();i++){
        for(int j = i + 1; j < min((int)strip.size(),8) && (strip[j].second - strip[i].second) < min_dist; j++){
            float d = dist(strip[i], strip[j]);
            if (d < min_strip_dist) {
                min_strip_dist = d;
                closest_pair = {strip[i], strip[j]};
            }
        }
    }
    return closest_pair;
}

pair<pair<int,int>,pair<int,int>> closestpair(vector<pair<int, int>> &points_x, vector<pair<int, int>> &points_y){
    int n=points_x.size();
    if(n<=3){
        float min_dist = FLT_MAX;
        pair<int, int> p1, p2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                float d = dist(points_x[i], points_x[j]);
                if (d < min_dist) {
                    min_dist = d;
                    p1 = points_x[i];
                    p2 = points_x[j];
                }
            }
        }
        return {p1, p2};
    }

    int mid=n/2;
    vector<pair<int, int>> left_x(points_x.begin(), points_x.begin() + mid);
    vector<pair<int, int>> right_x(points_x.begin() + mid, points_x.end());
    vector<pair<int, int>> left_y, right_y;
    for (const auto &point : points_y) {
        if (point.first <= points_x[mid].first) {
            left_y.push_back(point);
        } else {
            right_y.push_back(point);
        }
    }
    
    pair<pair<int,int>,pair<int,int>> left_pair, right_pair,split_pair;
    left_pair= closestpair(left_x, left_y);
    right_pair = closestpair(right_x, right_y);
    
    float left_dist = dist(left_pair.first, left_pair.second);
    float right_dist = dist(right_pair.first, right_pair.second);
    float min_dist = min(left_dist, right_dist);
    
    split_pair= closestsplitpair(points_y, min_dist, points_x[mid]);
    float split_dist = dist(split_pair.first, split_pair.second);
    
    if (split_pair.first.first != INT_MAX && split_dist < min_dist){
        return split_pair;
    } 
    else if(left_dist < right_dist){
        return left_pair;
    } 
    else{
        return right_pair;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        int x,y;
        cin>> x >> y;
        points[i] = {x, y};
    }
    vector<pair<int, int>> points_x = points;
    vector<pair<int, int>> points_y = points;
    sort(points_x.begin(), points_x.end(), comparex);
    sort(points_y.begin(), points_y.end(), comparey);

    pair<pair<int,int>,pair<int,int>> closest_pair = closestpair(points_x, points_y);
    cout << "Closest pair: (" << closest_pair.first.first << ", " << closest_pair.first.second << ") and ("
         << closest_pair.second.first << ", " << closest_pair.second.second << ")\n";
    cout << "Distance: " << fixed << setprecision(6) << dist(closest_pair.first, closest_pair.second) << "\n";
    return 0;
}