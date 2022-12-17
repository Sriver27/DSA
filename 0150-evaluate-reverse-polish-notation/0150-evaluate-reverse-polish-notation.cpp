class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<long long> s;
	for(auto& t : tokens) 
		if(t == "+" || t == "-" || t == "*" || t == "/") {
            
            /* Once we've found a operator we take out top two elements and perform arithmetic according to operator and push the result back into the stack */
            
			long long op1 = s.top(); s.pop();
			long long op2 = s.top(); s.pop();
			if(t == "+") op1 = op2 + op1;
			if(t == "-") op1 = op2 - op1;
			if(t == "/") op1 = op2 / op1;
			if(t == "*") op1 = op2 * op1;   
			s.push(op1);
		}
		else s.push(stoll(t));    // till we don't find any operator push the elements in the stack    
	return s.top(); 
        
    }
};