/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

#include <stdio.h>

#define MAX_ROOMS 5  //  max number of rooms

// Function prototypes
void initializeSystem(int lights[], int temp[], int motion[], int locks[]);
void displayMenu();
void controlLights(int lights[]);
void readTemperature(int temp[]);
void detectMotion(int motion[]);
void securitySystem(int locks[]);
void analyzeHouseStatus(int lights[], int temp[], int motion[], int locks[]);

int main() {
    int lights[MAX_ROOMS];
    int temp[MAX_ROOMS];
    int motion[MAX_ROOMS];
    int locks[MAX_ROOMS];
    int choice;

    // Initialize system
    initializeSystem(lights, temp, motion, locks);

    // Main menu loop
    do {
        displayMenu();                                                                                                        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            controlLights(lights);
        }
        else if (choice == 2) {
            readTemperature(temp);
        }
        else if (choice == 3) {
            detectMotion(motion);
        }
        else if (choice == 4) {
            securitySystem(locks);
        }
        else if (choice == 5) {
            analyzeHouseStatus(lights, temp, motion, locks);
        }
        else if (choice == 6) {
            printf("Exiting...!\n");
        }
        else {
            printf("Invalid choice...! Please try again.\n");
        }
        
    } while (choice != 6);

    return 0;
}

 
void initializeSystem(int lights[], int temp[], int motion[], int locks[]) {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        lights[i] = 0;   // 0 means OFF
        temp[i] = 25;    // default temperature
        motion[i] = 0;   // 0 means no motion
        locks[i] = 1;    // 1 means locked
    }
    printf("System initialized...!\n");
  
}

void displayMenu() {
    printf("\n====== Smart Home Menu ======\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}
void controlLights(int lights[]) {
    int roomNum;
    printf("Enter room number to toggle light(1-%d): ", MAX_ROOMS);
    scanf("%d", &roomNum);
    
    if (roomNum < 1 || roomNum > MAX_ROOMS) {
        printf("Invalid room number...!\n");
        return;
    }
    
    if (lights[roomNum - 1] == 0) {
        lights[roomNum - 1] = 1;
        printf("Light in room %d is now ON...!\n", roomNum);
    } else {
        lights[roomNum - 1] = 0;
        printf("Light in room %d is now OFF...!\n", roomNum);
    }
}
void readTemperature(int temp[]) {
    int roomNum;
    printf("Enter room number to read temperature(1-%d): ", MAX_ROOMS);
    scanf("%d", &roomNum);
    
    if (roomNum < 1 || roomNum > MAX_ROOMS) {
        printf("Invalid room number...!\n");
        return;
    }
    
    printf("Temperature in room %d is %d°C...!\n", roomNum, temp[roomNum - 1]);
}
void detectMotion(int motion[]) {
    int roomNum;
    printf("Enter room number to detect motion(1-%d): ", MAX_ROOMS);
    scanf("%d", &roomNum);
    
    if (roomNum < 1 || roomNum > MAX_ROOMS) {
        printf("Invalid room number...!\n");
        return;
    }
    
    if (motion[roomNum - 1] == 1) {
        printf("Motion detected in room %d...!\n", roomNum);
    } else {
        printf("No motion detected in room %d...!\n", roomNum);
    }
}
void securitySystem(int locks[]) {
    int roomNum;
    printf("Enter room number to lock/unlock door(1-%d): ", MAX_ROOMS);
    scanf("%d", &roomNum);
    
    if (roomNum < 1 || roomNum > MAX_ROOMS) {
        printf("Invalid room number...!\n");
        return;
    }
    
    if (locks[roomNum - 1] == 1) {
        locks[roomNum - 1] = 0;
        printf("Door in room %d is now UNLOCKED...!\n", roomNum);
    } else {
        locks[roomNum - 1] = 1;
        printf("Door in room %d is now LOCKED...!\n", roomNum);
    }
}
void analyzeHouseStatus(int lights[], int temp[], int motion[], int locks[]) {
    int i;
    printf("\n====================== House Status Summary ======================\n");
    for (i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d: Light=%s, Temperature=%d°C, Motion=%s, Lock=%s\n", i + 1,
               lights[i] == 1 ? "ON" : "OFF",
               temp[i],
               motion[i] == 1 ? "MOTION DETECTED" : "NO MOTION",
               locks[i] == 1 ? "LOCKED" : "UNLOCKED");
    }
}
