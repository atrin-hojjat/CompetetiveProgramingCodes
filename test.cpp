
#include <iostream>
#include <fann.h>
#include <chrono>

using namespace std;
using namespace chrono;

int main(int argc,char** argv){
const int input_num = 40;
    const int test_num = 10;
    const int point_num = 80;
    const int max_iters = 10000;
    const double learning_rate = 0.1;

    auto goal_func = [](double x)-> double{
        return sin(M_PI*x/2); // return cos(3*M_PI*x/2);
    };
{
        float **__input = new float*[input_num];
        float **__output = new float*[input_num];
        float x,y; cout << __LINE__ << endl;

        for (int j = 0; j < 40; ++j) {
            x = -2+j*0.1;y=goal_func(x);
            __input[j]=new float[1];
            __output[j]=new float[1];
			__input[j][0] = x;
			__output[j][0] = y;
        }
		cout << __LINE__ << endl;


        for (int t = 0; t < test_num; ++t) {
            cout << "[!] Test " << t+1 << " : " << endl;
            float **input = new float*[input_num];
            float **output = new float*[input_num];

            memcpy(input,__input,sizeof __input * sizeof __input[0]);
            memcpy(output,__output,sizeof __output * sizeof __output[0]);
			const unsigned int layers[3] = {1,8,1};
            struct fann *ann = fann_create_standard_array(3,layers);
            fann_set_activation_function_hidden(ann,FANN_SIGMOID);
            fann_set_activation_function_output(ann,FANN_LINEAR);
            struct fann_train_data *train_data = fann_create_train(input_num,1,1);
            train_data->input = input;train_data->output = output;
			cout << __LINE__  << " Atrin"<< endl;
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            fann_train_on_data(ann,train_data,max_iters,100,1e-5);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
			 cout << __LINE__ << endl;
            auto duration = duration_cast<seconds>( t2 - t1 ).count();



cout << __LINE__ <<endl;
            float err = 0;
            for (int j = 0; j < point_num; ++j) {
                float x = -2 + j*0.05;
                float out = *fann_run(ann,&x);
                err += pow(goal_func(x)-out,2);
            }
            err/=point_num;
            cout << "~~~ Mean Squered Error : " << err << endl;
        }
cout << __LINE__ << endl;

    }
	return 0;
}
