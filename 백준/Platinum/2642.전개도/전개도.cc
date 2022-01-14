#include <bits/stdc++.h>

using namespace std;

enum posi{
    TOP,
    BOT,
    NORTH,
    SOUTH,
    EAST,
    WEST,
    NP
};

enum direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

map<posi, vector<posi>> m = {{NORTH, {WEST, TOP, EAST, BOT}}, {SOUTH, {WEST, BOT, EAST, TOP}}, {EAST, {BOT, NORTH, TOP, SOUTH}}, {WEST, {TOP, NORTH, BOT, SOUTH}}, {BOT, {WEST, NORTH, EAST, SOUTH}}, {TOP, {EAST, NORTH, WEST, SOUTH}}};
map<posi, int> chk = {{NORTH, 0}, {SOUTH, 0}, {EAST, 0}, {WEST, 0}, {TOP, 0}, {BOT, 0}};
map<direction, direction> dir_m = {{LEFT, RIGHT}, {RIGHT, LEFT}, {UP, DOWN}, {DOWN, UP}};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
direction direct[4] = {LEFT, UP, RIGHT, DOWN};

class surface{
    
public:
    posi pos;
    int t;

    surface(){
        this->pos = NP;
        this->t = 0;
    };
    surface(posi a, posi from, direction d){

        this->pos = a;
        direction target = dir_m[d];
        if(from == NP) t= 0; 
        else{
            for(int i = 0; i < 4; i++){
                if(direct[i] == target){
                    for(int j = 0; j < 4; j++){
                        if(m[a][(i+j)%4] == from){
                            this->t = j;
                            break;
                        }
                    }        
                }
            }
            
        }
    }

    posi get_position(){
        return this->pos;
    }

    posi next_surface(int idx){
        return m[this->pos][(idx+this->t)%4];
    }

};

vector<surface> curr;
surface *one;
int arr[6][6];
surface surf[6][6];
int vs[6][6];
posi pos_one = NP;
posi list_of_position[6] = {NORTH, SOUTH, EAST, WEST, TOP, BOT};


void find_dir(int x, int y){

    surface &surface_curr = surf[x][y];
    vs[x][y] = 1;
    chk[surface_curr.get_position()] = arr[x][y];
    if(arr[x][y] == 1) pos_one = surface_curr.get_position();
    for(int i = 0; i < 4; i++){
        if(x+dx[i] >=0 && x+dx[i] < 6 && y+dy[i] >=0 && y+dy[i] < 6 && arr[x+dx[i]][y+dy[i]] && !vs[x+dx[i]][y+dy[i]]){
            surf[x+dx[i]][y+dy[i]] = surface(surface_curr.next_surface(i), surface_curr.get_position(), direct[i]);
            find_dir(x+dx[i], y+dy[i]);
        }
    }
}

// function for current position <-> position of current in next surface
// idx of current position+2%4


void solve(){

    int start_x=0, start_y=0;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cin >> arr[i][j];
            if(arr[i][j] && start_x == 0){
                start_x = i;
                start_y = j;
            }
        }
    }

    surf[start_x][start_y] = surface(BOT, NP, direct[0]);

    find_dir(start_x, start_y);

    bool works = true;
    for(int i = 0; i < 6; i++){
        if(chk[list_of_position[i]] == 0){
            cout << 0 << endl;
            works = false;
            return;
        } 
    }

    if(works){
        if(pos_one == BOT) cout << chk[TOP] << endl;
        else if(pos_one == TOP) cout << chk[BOT] << endl;
        else if(pos_one == WEST) cout << chk[EAST] << endl;
        else if(pos_one == EAST) cout << chk[WEST] << endl;
        else if(pos_one == SOUTH) cout << chk[NORTH] << endl;
        else cout << chk[SOUTH] << endl; 
    }

    // for(int i = 0; i < 6; i++){
    //     for(int j = 0; j < 6; j++){
    //         cout << surf[i][j].get_position() << ' ';
    //     }
    //     cout << endl;
    // }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}