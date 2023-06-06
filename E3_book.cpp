/*A book consists of chapters, chapters consist of sections and sections consist of subsections. Construct a tree and print the nodes.Find the time and space requirements of your method*/

#include<iostream>
using namespace std;

struct node
{
    char label[10];
    int ch_count;
    struct node *child[10];
}*root;

class Tree
{
    public:
        void create_tree();
        void display(node*r1);
         Tree()
         {
            root=NULL;
         }
};
void Tree::create_tree()
{
    int tch,i,j,k;
    root=new node;
    cout<<"Enter the name of book:"<<endl;
    cin>>root->label;
    cout<<"Enter the number of chapters in the book:"<<endl;
    cin>>tch;
    root->ch_count=tch;
    for(i=0;i<tch;i++)
    {
        root->child[i]=new node;
        cout<<"Enter Chapter "<<i+1<<" name: "<<endl;
        cin>>root->child[i]->label;
        cout<<"Enter the number of sections: "<<endl;
        cin>>root->child[i]->ch_count;

        for(j=0;j<root->child[i]->ch_count;j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"Enter section "<<j+1<<" name: "<<endl;
            cin>>root->child[i]->child[j]->label;
            cout<<"Enter the number of sub-sections: "<<endl;
            cin>>root->child[i]->child[j]->ch_count;
      
            for(k=0;k< root->child[i]->child[j]->ch_count;k++)
            {
                root->child[i]->child[j]->child[k]=new node;
                cout<<"Enter sub-section "<<j+1<<"."<<k+1<<" Title: "<<endl;
                cin>>root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}
void Tree ::display(node *r1)
{
    int tch,i,j,k;
    if (r1!=NULL)
    {
        cout<<"Book Tree Hierarchy :"<<endl;
        tch=r1->ch_count;
        for(i=0;i<tch;i++)
        {
            cout<<"Chapter: "<<i+1<<endl;
            cout<<" "<<r1->child[i]->label<<endl;
            for(j=0;j<r1->child[i]->ch_count;j++)
            {
                cout<<"Section: "<<j+1<<endl;
                cout<<r1->child[i]->child[j]->label<<endl;
                for(k=0;k<r1->child[i]->child[j]->ch_count;k++)
                {
                    cout<<"Sub-Section:"<<endl;
                    cout<<r1->child[i]->child[j]->child[k]->label<<endl;
                }
            }
        }
    }
}
int main()
{
    int ch;
    Tree bt;
    while(1)
    {
        cout<<"***********************"<<endl;
        cout<<"       Book Tree       "<<endl;
        cout<<"***********************"<<endl;
        cout<<"1. Create"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Quit"<<endl;
        cout<<"Enter Your Choice: ";
        cout<<"***********************"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                bt.create_tree();
                cout<<"Tree Created.";
                break;
            case 2:
                bt.display(root);
                break;
            case 3:
                cout<<"Thank You.";
                //exit(1);
                break;
            default:
                cout<<"Invalid Choice!!!"<<endl;
        }
    }
    return 0;
};
