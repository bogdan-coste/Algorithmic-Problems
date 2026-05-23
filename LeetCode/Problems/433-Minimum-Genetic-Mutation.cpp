class Solution {
public:
    int minMutation(std::string startGene, std::string endGene, std::vector<std::string>& bank) {
        
      std::unordered_set<std::string> geneSet(bank.begin(), bank.end());
      if (startGene == endGene) return 0;

      std::queue<std::pair<std::string, int>> q;
      std::unordered_set<std::string> visited;
      q.push(std::make_pair(startGene, 0));
      visited.insert(startGene);

      std::string components = "ACGT";

      while(!q.empty()){

        auto [curr, steps] = q.front();
        q.pop();

        if(curr == endGene) return steps;

        for(int i = 0; i < 8; i++){

          char original = curr[i];

          for(char g: components){
            if(g == original) continue;

            std::string next = curr;

            next[i] = g;

            if (geneSet.count(next) && !visited.count(next)) {
                visited.insert(next);
                q.push({next, steps + 1});
            }
          }
        }
      }

      return -1;
    }
};
