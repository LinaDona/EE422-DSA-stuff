#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

const unsigned max1 = 100;
typedef unsigned graph[max1][max1];
graph g;
unsigned nb;
bool colored[max1];
unsigned color[max1];

void init(int nb){
    for(int i=0; i<nb-1; i++){
        for(int j=i+1; j<nb; j++){
            char answer;
            cout << "Is node " << i << " adjecent to " << j << " Enter Y(y) or N(n)\n";
            cin >> answer;
            if(toupper(answer) == 'Y'){
                g[i][j] = g [j][i] = 1;
            }
            
        }
    }
}

void coloring(int nb){
    //cout << "colring 1st\n";
    unsigned i = 0; // first uncolored node
    unsigned j = 0; // first color
    unsigned size = 0;
    unsigned adj[max1 - 1];
    bool candidate;
    while(i < nb){
        //cout << "colring 2st\n";
        colored[i] = true;
        color[i] = j;
        unsigned k = i + 1;
        size = 0;
        while(k < nb){
            //cout << "colring 3st\n";
            candidate = true;
            while(!colored[k] && !g[i][k]){
                if (size == 0){
                    colored[k] = true;
                    color[k] = j;
                    adj[size++] = k;
                }
                else {
                    candidate = true;
                    for(int l=0; l<size; l++){
                        if(g[k][adj[l]]){
                            candidate = false;
                            break;
                        }
                        if(candidate){
                            colored[k] = true;
                            color[k] = j;
                            adj[size++] = k;
                        }
                        
                    }                    
                }
                
            }
            k++;
            
        }
        k = i + 1;
        
        while(colored[k])
            k++;
        i = k;
        j++;
        
    }
    cout << "colring 4th\n";
    

}

void display(int nb){
    for(int i=0; i<nb; i++){
        cout << "The color of node" << i << "is" << color[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    int nb;
    cout << "Enter the number of nodes. It should be less or equal to " << max1 << ": ";
    cin >> nb;
    init(nb);
    coloring(nb);
    display(nb);
    return 0;
}
