#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <cmath>
#include <vector>

const double V = 1.0; // Speed
const int N = 3; // Time interval in seconds
const double R = 5.0; // Radius

void chaoticMovement(int studentId) {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 360.0);

    double x = 0.0, y = 0.0;
    double angle = distribution(generator);
    
    while (true) {
        // Move in the current direction
        x += V * cos(angle * M_PI / 180);
        y += V * sin(angle * M_PI / 180);
        
        // Print current position
        std::cout << "Student " << studentId << " Position: (" << x << ", " << y << ")\n";
        
        // Wait for N seconds
        std::this_thread::sleep_for(std::chrono::seconds(N));
        
        // Change direction randomly
        angle = distribution(generator);
    }
}

void circularMovement(int studentId) {
    double angle = 0.0;
    
    while (true) {
        // Calculate new position
        double x = R * cos(angle);
        double y = R * sin(angle);
        
        // Print current position
        std::cout << "Student Group " << studentId << " Position: (" << x << ", " << y << ")\n";
        
        // Move to the next position
        angle += (V / R);
        
        // Wait for a short time to simulate movement
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    int numStudents = 5;
    int numStudentGroups = 3;
    
    std::vector<std::thread> threads;
    
    // Create threads for students
    for (int i = 1; i <= numStudents; ++i) {
        threads.push_back(std::thread(chaoticMovement, i));
    }
    
    // Create threads for student groups
    for (int i = 1; i <= numStudentGroups; ++i) {
        threads.push_back(std::thread(circularMovement, i));
    }
    
    // Join all threads
    for (auto& th : threads) {
        th.join();
    }
    
    return 0;
}
