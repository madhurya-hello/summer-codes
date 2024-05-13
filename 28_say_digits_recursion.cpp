// Input: 413 | Output: four one three

void say(int n){
    
    string word[10]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    if(n==0){
        return;
    }
    say(n/10);
    cout<<word[n%10]<<" ";
}

int main(){
    int n=5795;
    say(n);
}