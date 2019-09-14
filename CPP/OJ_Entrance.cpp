//#include <iostream>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <math.h>
//#include <limits>
//#include <algorithm>
//#include <vector>
//#include <stack>
//#include <queue>
//#include <string>
//#include <map>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
//
//using namespace std;
//
//vector<int> bucket;
//struct action {
//    int from;
//    int to;
//    int water;
//};
//
//struct bucket_states {
//    vector<int> states_vector;
//    action ac;
//    bucket_states(int a, int b, int c, int from, int to, int water) {
//        states_vector.resize(3);
//        states_vector[0] = a;
//        states_vector[1] = b;
//        states_vector[2] = c;
//        ac.from = from;
//        ac.to = to;
//        ac.water = water;
//    }
//    bucket_states(){
//        states_vector.resize(3);
//    }
//    void set_action(int dump_water, int from, int to) {
//        ac.from = from;
//        ac.to = to;
//        ac.water = dump_water;
//    }
//    bool is_empty(int bucket_idx) {
//        if(bucket_idx > 2) {
//            return false;
//        }
//        return (states_vector[bucket_idx] == 0);
//    }
//    bool is_full(int bucket_idx) {
//        return (states_vector[bucket_idx] >= bucket[bucket_idx]);
//    }
//    bool is_final() {
//        return (states_vector[0] == 4 && states_vector[1] == 4);
//    }
//    bool dump_water(int from, int to, bucket_states& next) {
//        vector<int> bucket_water(this->states_vector);
//        //倒水数目是to桶剩余的空间
//        int dump_water = bucket[to] - states_vector[to];
//        //如果from中的水大于to桶剩余的空间，则倒出dunp_water的水量
//        if(bucket_water[from] >= dump_water) {
//            bucket_water[to] += dump_water;
//            bucket_water[from] -= dump_water;
//        } else {//否则倒出from桶中的所有水
//            dump_water = bucket_water[from];
//            bucket_water[to] += dump_water;
//            bucket_water[from] = 0;
//        }
//        if(dump_water > 0) {
//            next.states_vector = bucket_water;
//            next.set_action(dump_water, from, to);
//            return true;
//        }
//        return false;
//    }
//};
//
//void print_states(bucket_states& bucket){
//    cout << "bucket_states : " << bucket.states_vector[0] << " " <<
//         bucket.states_vector[1] << " " << bucket.states_vector[2] <<
//         "  from " << bucket.ac.from << " to " << bucket.ac.to <<
//         "  dump " << bucket.ac.water << "L water." << endl;
//
//}
//
//bool is_action_valid(bucket_states& cur, int from, int to) {
//    if((from != to) && !cur.is_empty(from) && !cur.is_full(to))
//        return true;
//    return false;
//}
//
//bool is_loop(vector<bucket_states>& states, bucket_states& next) {
//    int i = 0;
//    for(; i < states.size(); ++i) {
//        if(equal(next.states_vector.begin(), next.states_vector.end(),
//                 states[i].states_vector.begin()))
//            return true;
//    }
//    return false;
//}
//
//void DFS(vector<bucket_states>& states, int& cnt, int& shortest) {
//    bucket_states cur = states.back();
//    if(cur.is_final()) {
//        ++cnt;
//        shortest = min(shortest, static_cast<int>(states.size()));
//        for_each(states.begin(), states.end(), print_states);
//        cout << "=====================" << endl;
//        return;
//    }
//    for(int i = 0; i < 3; ++i)
//        for(int j = 0; j < 3; ++j) {
//            if(is_action_valid(cur, i, j)) {
//                bucket_states next_states;
//                bool is_dump = cur.dump_water(i, j, next_states);
//                if(is_dump && !is_loop(states, next_states)) {
//                    states.push_back(next_states);
//                    DFS(states, cnt, shortest);
//                    states.pop_back();
//                }
//            }
//        }
//}
//
//int main() {
//    int a,b,c,n;
//    cin >> a >> b >>c >>n;
//    bucket = vector<int>{a,b,c};
//    vector<bucket_states> states;
//    bucket_states x(c, 0, 0, -1, 0, c);
////    bucket_states y(0, b, 0, -1, 1, b);
////    bucket_states z(0, 0, c, -1, 2, c);
//    states.push_back(x);
////    states.push_back(y);
////    states.push_back(z);
//    int cnt = 0, shortest = INT_MAX;
//    DFS(states, cnt, shortest);
//    cout << "result size : " << cnt << " shortest : " << shortest <<endl;
//}
