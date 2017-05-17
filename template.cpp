


void run(int num_tries, bool do_debug){
 
}


int main(int argc, char *argv[]){
    if(argc == 1){
        run(5, true);   
    }
    else{
        int num_times = std::atoi(argv[1]); 
        run(num_times, false);
    }
    return 0;
}

