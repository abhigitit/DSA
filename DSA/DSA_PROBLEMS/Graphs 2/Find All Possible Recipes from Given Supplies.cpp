/*
Find All Possible Recipes from Given Supplies
*/
class Solution {
    map<string,int> recNum;
    map<string,vector<string>> ingRec;
    set<string> visited;
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        set<string> sup(supplies.begin(),supplies.end());
        for(int i=0;i<recipes.size();++i)
        {
            string recipe = recipes[i];
            recNum[recipe] = ingredients[i].size();
            for(auto st:ingredients[i]) {
                ingRec[st].push_back(recipe);
            }
        }

    queue<string> bfs;

    for(auto st:supplies)
    {
        bfs.push(st);
    }
    while(!bfs.empty())
    {
        string rec = bfs.front();
        bfs.pop();
        if(recNum.count(rec))
        {
            recNum[rec]--; //decrementing the ingredients it requires
            if(!recNum[rec]) sup.insert(rec); //adding it into supplies when all the ingredients mark this recipe
            
        }

        if(sup.count(rec))
        {
            for(auto nei:ingRec[rec])
            {
                bfs.push(nei);
            }
        }
    }
    vector<string> res;
    for(auto it:recNum)
    {
        if(it.second<=0)
            res.push_back(it.first);
    }
    return res;

    }


};
