/*
Single cycle check in array
*/

using namespace std;


int get_idx(int curr_idx,vector<int>& array)
{
  int jump = array[curr_idx];
  int next_idx = (curr_idx+jump)%(int)array.size();
  return next_idx<0 ? next_idx+array.size() : next_idx;
}
bool hasSingleCycle(vector<int> array) {
  int visited = 0;
  int len = array.size();
  int curr_idx = 0;
  while(visited<len)
    {
      if(visited>0 and curr_idx==0)
          return false;
      curr_idx = get_idx(curr_idx,array);
      visited++;
    }
  return curr_idx==0;
}
