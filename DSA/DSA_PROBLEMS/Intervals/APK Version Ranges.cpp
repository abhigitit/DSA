/* 
APK Version Ranges google question

*/



#include <bits/stdc++.h>

using namespace std;

bool isInRange(vector<int> range, int target)
{
    int minos = range[0];
    int maxos = range[1];
    return minos<=target and target<=maxos;
}
void bisectRight(int low, int high, int target, vector<vector<int>>& versions,int &latestVersion)
{
     while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(versions[mid][0]<=target)
        {
            if(isInRange(versions[mid],target))
                latestVersion = max(latestVersion,versions[mid][2]);
            low = mid+1;
        }
        else
            high = mid-1; 
    }
}

void bisectLeft(int low, int high, int target, vector<vector<int>>& versions,int &latestVersion)
{
    
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(versions[mid][0]<=target)
        {
            if(isInRange(versions[mid],target))
                latestVersion = max(latestVersion,versions[mid][2]);
            high = mid-1; 
        }
        else
            low = mid+1;
    }
}

int getLatestVersion(vector<vector<int>>& versions, int target)
{
    sort(versions.begin(),versions.end());
    int size = versions.size();
    int latestVersion = 0;
    bisectLeft(0,size-1,target,versions,latestVersion);
    bisectRight(0,size-1,target,versions,latestVersion);
    return latestVersion;
}

int main()
{
  
    vector<vector<int>> versions = {{14,10000,1}, {1,8,2},{12,16,3}};
    cout<<getLatestVersion(versions,14)<<endl;
    return 0;
}
