/*********************
Name: Saeid Jalaliani
Challenge 2 COSC 2436
Purpose: FIFO Stack (QUEUE)
**********************/
#include "main.h"

int main(){
    
    srand(time(NULL));
    
    FIFO queue;
    int stacksize;
    int tempNum, tempNum2, tempNum3;
    string strTemp;
    Data package;
    bool check;
    
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;
    
    stacksize = rand()%STACKSIZE+1;
    
    if(queue.isEmpty()){
        cout << "Stack is currently, empty. \n";
    }
    
    cout << "attempting to add " << stacksize << " objects to the stack.\n";
    
    for(int i = 0; i < stacksize; i++){
            
            tempNum = rand()%30-3; // sometimes we want to send an invalid num
        
            rand_string(&strTemp);
        
            check = queue.push(tempNum, &strTemp);
            
            cout << "Filling stack ..." << endl << endl;
            
            if (check) {
                cout << "pushed " << tempNum << ": " << strTemp << " successfully." << endl;
            } else {
                cout << "could not push element " << i+1 <<": " << tempNum << " to the stack, invalid entry. " << endl;
            }
            
            
     } 
     
     queue.peek(&package);
                
     cout << "peeking the top of the stack at this time: " << package.id << ": " << package.data << endl;
     
     tempNum = rand()%(TESTSIZE/2)-1;
     
     
     for(int i = 0; i < stacksize+(tempNum); i++){
         
         check = queue.pull(&package);
         
         if (check) {
             cout << i+1 << ": " << package.id << " " << package.data << endl;
         } else {
             cout << "could not pop anymore. Underflow!" << endl;
         }
     }

         check = queue.peek(&package);
        
        if(!check){
            cout << "Stack is empty, cannot peek! underflow. " << endl;
        } else {
            cout << "peeking the top of the stack at this time: " << package.id << ": " << package.data << endl; 
        } 
        
     for(int i = 0; i < NUM_TESTS; i++){
	
    	tempNum = rand()%6 + 1;
    	tempNum2 = rand()%number_test_cases;
        tempNum3 = rand()%30-3;
 
	
	cout << "random tests number " << i+1 << endl << endl;
	
	switch(tempNum){
		case 1:
		case 2: 
			for(int i=0; i < tempNum2; i++ ){
				
			rand_string(&strTemp);
		
			if(!queue.push(tempNum3+i, &strTemp)){
 
			cout << "Stack overflow reached!" << endl;
			}else{
				cout << "successfully pushed." << endl;
			}
				
		}
		break;
		case 3:
		case 4:
			for(int i=0; i<tempNum2;i++){
				queue.pull(&package);
				if(package.id == -1){
				cout << "stack underflow!" << endl;
			}else{
				cout << package.id << " - " << package.data << endl;
			}
		}
		break;
		case 5:
			queue.peek(&package);
			if(package.id > 0 && package.data.length()>0){
				cout << "Peeking at stack ID: " << package.id << " - info: " << package.data << endl;
			}else{
				cout <<"invalid data" << endl;
			}
		break;
		case 6: 
			if(queue.isEmpty()){
				cout << "stack is empty (in swtich statement)" << endl;
			}else{
				cout << "stack is not empty (in swtich statement)" << endl;
			}
		break;
	}
 
}

    cout << "attempting to add " << FINAL << " objects to the stack, to see if the destructor automatically clears everything when program ends. \n";
    
    for(int i = 0; i < FINAL; i++){
            
            tempNum = rand()%30-3; // sometimes we want to send an invalid num
        
            rand_string(&strTemp);
        
            check = queue.push(tempNum, &strTemp);
            
            cout << "Filling stack ..." << endl << endl;
            
            if (check) {
                cout << "pushed " << tempNum << ": " << strTemp << " successfully." << endl;
            } else {
                cout << "could not push element " << i+1 <<": " << tempNum << " to the stack, invalid entry. " << endl;
            }
            
            
     } 
        
    return 0;
}

void rand_string(std::string *str){
    // create size 0 to MAXSTRSIZE-1
    int rnum = rand() % MAXSTRSIZE;
    
    // make buffer to hold rand string
    char *buffer = new char[rnum+1];

    // fill buffer with random characters A to Z
    int i = 0;
    for(; i < rnum; i++){
        buffer[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
    }
    buffer[i] = '\0';

    // transfer buffer to passed in string
    *str = buffer;

    // clean up
    delete buffer;
    return;
}