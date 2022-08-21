class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        
        int n = energy.size();
        int extra_energy = 0, extra_exp = 0;
        
        for(int i = 0; i<n; ++i)
        {
            // make sure that current energy > energy[i] when we reach there, else add up the extra energy needed
            
            if(initialEnergy <= energy[i])
            {
                extra_energy += energy[i] - initialEnergy + 1;
                initialEnergy = energy[i]+1;
            }
            
            if(initialExperience <= experience[i])
            {
                extra_exp += experience[i] - initialExperience + 1;
                initialExperience = experience[i]+1;
            }
            
            initialEnergy -= energy[i];
            initialExperience += experience[i];
            
        }
        
        return extra_energy + extra_exp;
        
    }
};