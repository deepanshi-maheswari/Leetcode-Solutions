
class Car{
    public:
    int pos;
    int speed;

    Car(int p, int s){
        this->pos = p;
        this->speed = s;
    }
};

static bool compare(Car&a, Car&b){
    return a.pos < b.pos;
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;

        for(int i = 0; i < position.size(); i++){
            Car car(position[i], speed[i]);
            cars.push_back(car);
        }

        sort(cars.begin(), cars.end(), compare);

        stack<float> st;
        for(auto c: cars){
            float time = (target - c.pos)/ (float) c.speed;

            while(!st.empty() && time >= st.top()){
                st.pop();
            }
            st.push(time);
        }

        return st.size();
    }
};