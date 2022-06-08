![image](https://user-images.githubusercontent.com/82572503/172623266-7cde73f1-7e48-405a-9623-011dfa7879e1.png)

My app uses get_vector_sub_directories to get a vector of sub directories of C driven.Then this vector is divated between 4 threads that exeсuts search_in_folder function that checks contents of the folder and the main thread waits for result.Program ends when 1 of threads finds the target file or not finding the file( it doesnt exist)

Result:


![image](https://user-images.githubusercontent.com/82572503/172680105-8716f3f3-657a-4e53-bc33-1ca88ae52e78.png)
