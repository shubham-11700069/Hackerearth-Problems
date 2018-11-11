
#include<bits/stdc++.h>
using namespace std;
int n, a[100005];
vector< pair<int, int> > trav;
typedef struct node{
int data;
struct node *right, *left;
}node;

void inorder(node *root)
{
    if(root)
    {
            inorder(root->left);
            trav.push_back({root->data, 0});
            inorder(root->right);
    }
}
node* create(int idx)
{
    if(idx <= n)
    {
        node *temp=(node*)malloc(sizeof(node));
        temp->data = a[idx];
        temp->left = create(2*idx);
        temp->right = create(2*idx+1);
        return temp;
    }
    return NULL;
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    node *root = create(1);
    trav.push_back({0, 0});
    inorder(root);
    //for(int i=1;i<=n;i++)
        //cout<<trav[i].first<<"  "<<trav[i].second<<endl;
    for(int i=1;i<=n;i++)
    {
        trav[i].second=i;
    }
    //for(int i=1;i<=n;i++)
        //cout<<trav[i].first<<"  "<<trav[i].second<<endl;
    sort(trav.begin()+1, trav.end());
    bool vis[n+1];
    memset(vis, 0, sizeof(vis));
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (vis[i] || trav[i].second == i)
            continue;
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
            j = trav[j].second;
            cycle_size++;
        }
        ans += (cycle_size - 1);
    }
    cout<<ans<<endl;
}
