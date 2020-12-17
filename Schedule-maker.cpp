#include <iostream>
using namespace std;

struct Node {
    int data;
    int time;
    Node* left;
    Node* right;
};
// For creating the leaf node
Node* create(int data,int time)
{
    Node* temp = new Node();
    temp->left=temp->right = NULL;
    temp->data = data;
    temp->time = time;
    return temp;
}

//For inserting to appropriate side of the tree.

void insert(Node* &root, int data,int time)
{
        if(root== NULL)
            root = create(data,time);
    
    else if(root->data > data)
        insert(root->left, data,time);

    else
        insert(root->right, data,time);
}

//Displaying the left most node. Which is most efficient time to make a meeting.

Node* displayLeftMost(Node* root)
{
    Node *temp;
    while(root->left!=NULL)
    {
        root = root->left;
    }
    temp = root;
    return temp;
}
int main() {
    //1st Group 19-01, 2nd Group 18-04, 3rd Group 16-02
    
    //array[x][y][z] = 'x' for days, 'y' for 3 groupd which is above, 'z' for timeline which is below
    
    //0) 9-10 1)10-11 2) 11-12 3) 12-13 4) 13-14 5)14-15 6) 15-16 7)16-17 8)17-18
    int array[5][3][9] = {
        //Monday
        {
            //1st Group
            {0,1,1,1,1,0,0,0,0},
            //2nd Group
            {1,1,1,1,1,1,1,1,0},
            //3rd Group
            {0,1,1,0,1,1,0,0,0}
        },
        //Tuesday
        {
            //1st Group
            {1,1,0,0,0,1,1,1,0},
            //2nd Group
            {0,0,1,1,0,0,0,1,1},
            //3rd Group
            {0,1,1,0,0,0,0,0,0}
        },
        //Wednesday
        {
            //1st Group
            {0,0,0,0,1,1,1,1,1},
            //2nd Group
            {0,1,1,1,1,0,1,1,0},
            //3rd Group
            {1,1,1,1,1,1,0,1,1}
        },
        //Thursday
        {
            //1st Group
            {0,1,1,0,1,1,0,0,0},
            //2nd Group
            {1,1,1,0,0,0,0,0,0},
            //3rd Group
            {0,0,0,1,1,1,0,0,0}
        },
        //Friday
        {
            //1st Group
            {1,1,0,0,1,1,0,0,0},
            //2nd Group
            {0,0,0,0,1,1,1,1,0},
            //3rd Group
            {1,1,0,1,1,0,0,1,1}
        }
    };
    cout<<"Choose the day: "<<endl;
    cout<<"1.Monday\t 2.Tuesday\t 3.Wednesday\t 4.Thursday\t 5.Friday"<<endl;
    int x;
    cin>>x;
    x= x-1;
    int temp[9] = {};
    for(int i =0; i < 3; i++)
    {
        temp[0] += array[x][i][0];
        temp[1] += array[x][i][1];
        temp[2] += array[x][i][2];
        temp[3] += array[x][i][3];
        temp[4] += array[x][i][4];
        temp[5] += array[x][i][5];
        temp[6] += array[x][i][6];
        temp[7] += array[x][i][7];
        temp[8] += array[x][i][8];
    }
    Node* root = NULL;
    for(int i = 0; i<9; i++)
    {
        insert(root,temp[i], i);
    }
    string appTime;
    switch(displayLeftMost(root)->time)
    {
        case 0: {
            appTime = "9-10";
        }
            break;
        case 1: {
            appTime = "10-11";
        }
            break;
        case 2: {
            appTime = "11-12";
        }
            break;
        case 3: {
            appTime = "12-13";
        }
            break;
        case 4: {
            appTime = "13-14";
        }
            break;
        case 5: {
            appTime = "14-15";
        }
            break;
        case 6: {
            appTime = "15-16";
        }
            break;
        case 7: {
            appTime = "16-17";
        }
            break;
        case 8: {
            appTime = "17-18";
        }
            break;
    }
    int studentPercentage = (displayLeftMost(root)->data/3.0)*100.0;
    cout<<"The most efficient time to make a meeting is: "<<appTime<<endl;
    cout<<"At this time nearly: "<<100 - studentPercentage <<"% of students are free"<<endl;
    return 0;
}