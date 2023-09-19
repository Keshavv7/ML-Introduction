#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

void gradient(vector<double>& x, vector<double>& y)
{
    int iterations = 1000000;
    double m_curr = 0;
    double b_curr = 0;
    int n = x.size();
    float learning_rate = 0.0001;
    double factor = (double)(-2)/n;
    for (int i=0; i<iterations;i++)
    {
        vector<double> y_predicted;
        y_predicted.resize(n);
        fill(y_predicted.begin(), y_predicted.end(), 0);
        double md = 0;
        double bd = 0;
        for (int j=0; j<n; j++)
        {
            y_predicted[j] = m_curr*x[j]+b_curr;
            md+=x[j]*(y[j]-y_predicted[j]);
            bd+= (y[j]-y_predicted[j]);
        }
        md = md*factor;
        bd = bd*factor;
        m_curr = m_curr - learning_rate*md;
        b_curr = b_curr - learning_rate*bd;
    }
    cout<<"The values are m = "<<m_curr<<" and b = "<<b_curr<<endl;
}

int main()
{
    vector<double> x = {1,2,3,4,5};
    vector<double> y = {5,7,9,11,13};
    auto start = high_resolution_clock::now();
    gradient(x,y);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time taken: "<<duration.count()<<" microseconds"<<endl;
    return 0;
}