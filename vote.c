#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VOTERS 500
#define MAX_CANDIDATES 300

//Voter structure
typedef struct {
    int voter_id;
    char voter_name[50];
    int age;
    char address[256];
    char voter_state[50];
    int hasVoted; // 0: Not voted 1: Voted
} Voter;

//Candidate Structure
typedef struct {
    int candidate_id;
    char candidate_name[50];
    char party[50];
    char candidate_state[50];
    int vote_count;
} Candidate;

//Databases

Voter voters[MAX_VOTERS]; //Stores voter structures
Candidate candidates[MAX_CANDIDATES]; //Stores candidate structures
int voter_count = 0;
int candidate_count = 0;


//Utility Function
void clearInputbuffer(){
    while(getchar() != '\n');
}

//Declaration of functions used (Apart from utility function)

void register_voter();
void delete_voter();
void display_voter();
void search_voter();
void add_candidate();
void display_candidate();
void search_candidate();
void update_candidate_info();
void cast_votes();
void display_results();
void menu();


//Function to register voter
void register_voter(){
    Voter v; 
    
    if (voter_count >= MAX_VOTERS){
        printf("Voter database is full\n");
        return;
    }

    printf("Enter name: ");
    fgets(v.voter_name , sizeof(v.voter_name), stdin);
    v.voter_name[strcspn(v.voter_name , "\n")] = 0;

    printf("Enter age: ");
    scanf("%d", &v.age);
    clearInputbuffer();

    if (v.age < 18){
        printf("Voter is underage");
        return;
    }

    printf("Enter voter ID: ");
    scanf("%d", &v.voter_id);
    clearInputbuffer();

    printf("Enter voter address: ");
    fgets(v.address, sizeof(v.address), stdin);
    v.address[strcspn(v.address, "\n")] = 0;

    printf("Enter state vote is being casted in: ");
    fgets(v.voter_state, sizeof(v.voter_state), stdin);
    v.voter_state[strcspn(v.voter_state, "\n")] = 0;

    v.hasVoted = 0;

    voters[voter_count++] = v ;
    printf("Voter registration is complete\n");

}

void delete_voter(){
    char temp[50];
    int i, j;
    printf("Enter name of the voter to delete: ");
    fgets(temp, sizeof(temp), stdin);

    for(i=0; i<voter_count; i++){
        if(strcmp(temp, voters[i].voter_name) == 0){
            for(j=i; j<voter_count-1; j++){
                voters[j] = voters[j+1];
            }
            voter_count--;
            printf("Voter deleted.");
            return;
        }    
    }
    printf("Voter not found.");
}

//Function to display voter details
void display_voter(){

    if (voter_count == 0){
        printf("Nobody has voted yet");
        return;
    }

    for (int i = 0; i < voter_count ; i++){
        printf("Voter %d : \n", i + 1);
        printf("Name: %s \n", voters[i].voter_name);
        printf("Age: %d \n", voters[i].age);
        printf("Voter ID: %d \n", voters[i].voter_id);
        printf("Address: %s \n", voters[i].address);
        printf("State: %s \n", voters[i].voter_state);
        printf("Voting status: %s \n", voters[i].hasVoted ? "Voted" : "Not Voted");
        printf("\n");
    }
}

//Function to search for voter by name or voter ID and display their details if found
void search_voter(){
    char name_temp[50];
    printf("Enter name of the voter whose details you wish to search: ");
    fgets(name_temp, sizeof(name_temp), stdin);
    name_temp[strcspn(name_temp, "\n")] = 0;

    for (int i = 0; i < voter_count; i++){
        if (strcmp(name_temp, voters[i].voter_name) == 0){
            printf("Voter %d : \n", i + 1);
            printf("Name: %s \n", voters[i].voter_name);
            printf("Age: %d \n", voters[i].age);
            printf("Voter ID: %d \n", voters[i].voter_id);
            printf("Address: %s \n", voters[i].address);
            printf("State: %s \n", voters[i].voter_state);
            printf("Voting status: %s \n", voters[i].hasVoted ? "Voted" : "Not Voted");
            return ;
        }
    }

    printf("Voter not found");
}

void add_candidate(){
    Candidate c;

    if (candidate_count >= MAX_CANDIDATES){
        printf("Candidate database is full");
    }

    printf("Enter name of candidate: ");
    fgets(c.candidate_name, sizeof(c.candidate_name), stdin);
    c.candidate_name[strcspn(c.candidate_name, "\n")];

    printf("Enter candidate ID: ");
    scanf("%d", &c.candidate_id);
    clearInputbuffer();

    printf("Enter party name: ");
    fgets(c.party, sizeof(c.party), stdin);
    c.party[strcspn(c.party, "\n")] = 0;

    printf("Enter state in which party is contesting the election: ");
    fgets(c.candidate_state, sizeof(c.candidate_state), stdin);
    c.candidate_state[strcspn(c.candidate_state, "\n")] = 0;

    c.vote_count = 0;
    candidates[candidate_count++] = c ;

    printf("Candidate has been added\n");
  
}

//Function to display candidate details
void display_candidate(){
    if (candidate_count == 0){
        printf("No candidate has been added\n");
        return;
    }

    for (int i = 0; i < candidate_count; i++){
        printf("Candidate Details:\n");
        printf("Candidate Name: %s \n", candidates[i].candidate_name);
        printf("Candidate ID: %d \n", candidates[i].candidate_id);
        printf("Candidate Party: %s \n", candidates[i].party);
        printf("State in which candidate is contesting the election: %s \n", candidates[i].candidate_state);
        printf("Vote Count of candidate: %d\n", candidates[i].vote_count );
        printf("\n");
    }
}

//Function to search for candidate using candidate ID and display their details

void search_candidate(){
    int temp_id;
    printf("Enter Candidate ID: ");
    scanf("%d", &temp_id);
    

    for (int i = 0; i < candidate_count; i++){
        if (temp_id == candidates[i].candidate_id){
            printf("Candidate found. Displaying candidate details...\n");
            printf("Candidate Name: %s \n", candidates[i].candidate_name);
            printf("Candidate ID: %d \n", candidates[i].candidate_id);
            printf("Candidate Party: %s \n", candidates[i].party);
            printf("State in which candidate is contesting the election: %s \n", candidates[i].candidate_state);
            printf("Vote Count of candidate: %d\n", candidates[i].vote_count );
            printf("\n");
            
        }

        else{
            printf("Candidate not found\n");
        }
    }

  

}

void update_candidate_info(){

    int id;
    printf("Enter id of candidate to be updated: ");
    scanf("%d", &id);

    for (int i = 0; i < candidate_count; i++){
        if (id == candidates[i].candidate_id){
            printf("Enter updated name of candidate: ");
            fgets(candidates[i].candidate_name, sizeof(candidates[i].candidate_name), stdin);
            candidates[i].candidate_name[strcspn(candidates[i].candidate_name, "\n")] = 0;

            printf("Enter updated candidate ID: ");
            scanf("%d", &candidates[i].candidate_id);
            clearInputbuffer();

            printf("Enter updated party: ");
            fgets(candidates[i].party, sizeof(candidates[i].party), stdin);
            candidates[i].party[strcspn(candidates[i].party, "\n")] = 0;

            printf("Enter updated candidate state: ");
            fgets(candidates[i].candidate_state, sizeof(candidates[i].candidate_state), stdin);
            candidates[i].candidate_state[strcspn(candidates[i].candidate_state, "\n")] = 0;

            return;
            
        }
    }

    printf("Candidate information has been updated. \n");
}

void cast_votes(){

    int temp_candidateID; int temp_voterID;

    printf("Enter voter ID: ");
    scanf("%d", &temp_voterID);
    clearInputbuffer();

    for (int i = 0; i < voter_count; i++){
        if (temp_voterID == voters[i].voter_id){
            if (voters[i].hasVoted){
                printf("You have already casted your vote.\n");
                return;
            }

            voters[i].hasVoted = 0;

            printf("\tCandidates Available:\t\n");

            if (candidate_count == 0){
                printf("No candidates registered yet\n");
                return;
            }

            display_candidate();

            printf("Please cast your vote for your desired candidate.\n");
            printf("To cast your vote, please enter the candidate ID of desired candidate\n");
            scanf("%d", &temp_candidateID );
            clearInputbuffer();
            
            for (int i = 0; i < candidate_count; i++){
                if (temp_candidateID == candidates[i].candidate_id){
                candidates[i].vote_count++;
                printf("Vote has been cast. Thank you for your cooperation.\n");
                }

                else {
                    printf("Invalid Candidate ID\n");
                }
            }

            voters[i].hasVoted = 1;
            return;
            
        }
    }

    printf("Invalid voter ID\n");
}

void display_results(){
    if (candidate_count == 0){
        printf("No candidates took part in election");
        return;
    }
    
    printf("After counting, the vote count of each candidate stands as follows: \n");
    for (int i = 0; i < candidate_count; i++){
        printf("Candidate: %s , ID: %d, Vote Count : %d \n", candidates[i].candidate_name, candidates[i].candidate_id, candidates[i].vote_count);
    }
}

void menu(){
    int choice;

    do {
        printf("\tMENU\t\n");
        printf("1.Voter Registration\n");
        printf("2.Display Voter Details\n");
        printf("3.Search for a voter\n");
        printf("4.Add a Candidate\n");
        printf("5.Display Candidate information\n");
        printf("6.Search for a candidate\n");
        printf("7.Update Candidate Information\n");
        printf("8.Cast votes\n");
        printf("9.Display the Results\n");
        printf("10.Exit\n");
        printf("11.Delete voter\n");

        printf("Enter your choice (1-11): ");
        scanf("%d", &choice);
        clearInputbuffer();

        switch(choice){
            case 1: register_voter();
                    break;
            case 2: display_voter();
                    break;
            case 3: search_voter();
                    break;
            case 4: add_candidate();
                    break;
            case 5: display_candidate();
                    break;
            case 6: search_candidate();
                    break;
            case 7: update_candidate_info();
                    break;
            case 8: cast_votes();
                    break;
            case 9: display_results();
                    break;
            case 10:printf("Exiting...\n");
                    break;
            case 11:delete_voter();
                    break;
            default:printf("Invalid choice\n");
                    break;
        }
        
    } while(choice != 10);
}

int main(){
    menu();
    return 0;
}
