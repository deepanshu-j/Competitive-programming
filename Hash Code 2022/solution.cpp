/*      AUTHOR: Deepanshu Johar 
        codeforces: Dj46
*/
// #include<bits/stdc++.h>

// /**
#include<iostream>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
// */

using namespace std;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(int i=a ; i<(b) ; ++i )
#define endl "\n"
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define debug(x) cout<<#x<<" : "<<x<<"\n";
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
void solve(){
    
    /// INPUTS ///
    
    int contributors, projects;
    cin>>contributors>>projects;
    
    
    map<string, vector<pair<int, string>> > mp; // skill to contibutor mapping //
    // eg For "C++" we have contibutors list as <2,"anna"> <3, "banna"> ...  sort acc to skill level // 
    
    
    rep(i,0,contributors){
        // input for contributors //
        string name;
        cin>>name;
        
        int skill_cnt;
        cin>>skill_cnt;
        
        rep(j,0,skill_cnt){
            
            string skill;
            cin>>skill;  
            
            int skill_level;
            cin>>skill_level;
            
            mp[skill].eb( make_pair(skill_level, name) );
        }
    }
    
    
    for(auto &x: mp){
        
        sort( all(x.ss), [](pair<int, string> &left, pair<int, string> &right){
            return left.ff < right.ff;
        }); 
        
    }
    
    map<string, vector< pair<string, int> > > mp2; // reqd_skills for a particular project //
    // eg "logging" -> <"c++", 3> reqd c++ contributur of level 3 //
    
    vector<pair<int, string>> pj_sequence; // the project sequence in which i will try to exec them // 
    
    rep(i,0,projects){
        // input for projects //
        string project_name;
        cin>>project_name;
        
        int days, completion_score, best_before, no_of_roles;
        cin>>days>>completion_score>>best_before>>no_of_roles;
        
        
        /////// Greedily selecting projects to exec them ////////
        // int my_greedy_score = (1LL*100000*completion_score)/(1LL*days*best_before);
        srand(time(0));
        int my_greedy_score = best_before; //(1LL*100LL*best_before*days)/(1LL*completion_score);

        pj_sequence.eb( make_pair(my_greedy_score, project_name) );
        ///////////// //////////////
        
        
        rep(j,0,no_of_roles){
            
            string reqd_skill;
            cin>>reqd_skill;
            
            int reqd_level;
            cin>>reqd_level;
            
            mp2[project_name].eb( make_pair(reqd_skill, reqd_level) );  
        }
    }
    
    
    /// INPUT END HERE ///
    
    // int stupid_input_check=1951;
    // cin>>stupid_input_check;
    // debug(stupid_input_check);
    
    sort(all(pj_sequence), [](pair<int, string> &left, pair<int, string> &right){
        return left.ff > right.ff;
    });
    
    int executed_project_cnt = 0;
    
    vector< pair<string, vector<string>> > res;
    
    rep(i,0,pj_sequence.size()){
        
        string project_name = pj_sequence[i].ss;
        
        bool executed=false;
        vector<string> this_project_contributors;
        // try to execute it //
        set<string> seen; // already taken contributors //
        
        vector< pair<string, int> >  reqd_skills = mp2[project_name];
        
        rep(i,0, reqd_skills.size()){
            
            int this_task_done=0;
            // 
            string reqd_skill_name = reqd_skills[i].ff;
            int reqd_skill_level = reqd_skills[i].ss;
            
            // serach in that skill do we have anybody //
            
            vector<pair<int, string>> given_contributors =  mp[reqd_skill_name];
            rep(i,0,given_contributors.size()){
                if(given_contributors[i].ff >= reqd_skill_level and seen.count(given_contributors[i].ss)==0 ){
                    seen.insert(given_contributors[i].ss);
                    this_project_contributors.eb(given_contributors[i].ss);
                    this_task_done |= 1;
                    break;
                }
            }
            
            if(!this_task_done){
                break;
            }else if(this_task_done and i==reqd_skills.size()-1){
                executed=true; // all tasks are executed //
            }
        }
        
        if(executed){
            ++executed_project_cnt;
            // add to result //
            res.eb( make_pair(project_name, this_project_contributors) );
            
        }
    }
    
    // printing ANS //
    cout<<executed_project_cnt<<"\n";
    for(auto &x: res){
        string project_name = x.ff;
        cout<<project_name<<"\n";
        for(auto &person: x.ss){
            cout<<person<<" ";
        }
        cout<<"\n";
    }
    
}
int main() {
	fast_io;

    // t1 //

    vector<string> input_files{
        "a_an_example",
        "b_better_start_small",
        "c_collaboration",
        "d_dense_schedule",
        "e_exceptional_skills",
        "f_find_great_mentors"};

    // freopen("a_an_example.in.txt" , "r" , stdin) ;
    // freopen("a_an_example.out.txt" , "w" , stdout) ;

    // freopen("b_better_start_small.in.txt" , "r" , stdin) ;
    // freopen("b_better_start_small.out.txt" , "w" , stdout) ;

    freopen("c_collaboration.in.txt" , "r" , stdin) ;
    freopen("c_collaboration.out.txt" , "w" , stdout) ;

    // freopen("d_dense_schedule.in.txt" , "r" , stdin) ;
    // freopen("d_dense_schedule.out.txt" , "w" , stdout) ;

    // freopen("e_exceptional_skills.in.txt" , "r" , stdin) ;
    // freopen("e_exceptional_skills.out.txt" , "w" , stdout) ;

    // freopen("f_find_great_mentors.in.txt" , "r" , stdin) ;
    // freopen("f_find_great_mentors.out.txt" , "w" , stdout) ;


	ll t=1;
// 	cin>>t;
	rep(i,1,t+1)
	{
	   // cout<<"Case: #"<<t<<"\n";
	    solve();
	}
	return 0;
}
