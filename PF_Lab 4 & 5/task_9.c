#include <stdio.h>
#include<string.h>
int main(){
    int year;
    int program;
    printf("Enter your program in which you slect:\n");
    printf("1.BSCS\n");
    printf("2.EE\n");
    printf("1.BBA\n");
    printf("Enter numer(1-3): ");
    
    scanf("%d", &program);
    switch (program)
    {
    case 1:
        printf("You are the student of EE.\n\n");
        printf("First semester courses:\n\t1. Introduction to Computer Science\n\t2. Programing Fundamentals\n\t3. Applied Physics\n\t4. Calculus & Analytical Geometry\n\t5. Functional English\n\t6. Pakistan Studies\n\t7. Islamic Studies\n\n");
        printf("Second semester courses:\n\t1. Object Oriented Programming\n\t2. Digital Logic Design\n\t3. Multivariable Calculus\n\t4. Islamic Studies/Ethics\n\t5. Expository Writing\n\n");
        printf("Fourth semester courses:\n\t1. Database Systems\n\t2. Operating Systems\n\t3. Technical and Business Writing\n\t4. Probability and Statistics\n\t5. Elective - II\n\t6. Computing Internship\n\n");
        printf("Third semester courses:\n\t1. Data Structures\n\t2. Computer Organization and Assembly Language\n\t3. Discrete Structures\n\t4. Linear Algebra\n\t5. Elective - I\n\t6. Civics and Community Engagement\n\n");
        printf("Fifth semester courses:\n\t1. Theory of Automata\n\t2. Computer Networks\n\t3. CS Elective - I\n\t4. Design and Analysis of Algorithms\n\t5. CS Elective - II\n\n");
        printf("Sixth semester courses:\n\t1. Software Engineering\n\t2. Computer Architecture\n\t3. Artificial Intelligence\n\t4. CS Elective - III\n\t5. Applied Human Computer Interaction\n\n");
        printf("Seventh semester courses:\n\t1. Final Year Project-I\n\t2. Information Security\n\t3. CS Elective - IV\n\t4. Professional Practices\n\t5. Compiler Construction\n\t6. Parallel and Distributed Computing\n\n");
        printf("Eighth semester courses:\n\t1. Final Year Project-II\n\t2. Entrepreneurship\n\t3. CS Elective - V\n\t4. CS Elective - VI\n\t5. Advanced Database Management System\n\n");
        switch (year)
        {
            printf("Enter your semister = ");
            scanf("%d", &year);
            
        case 1:
            
            break;
        
        default:
            break;
        }
        break;
    case 2: 
        printf("You are the student of EE.\n\n");      
        printf("First semester courses:\n\t1. Applications of ICT\n\t2. Applied Calculus\n\t3. Applied Physics\n\t4. Engineering Drawing\n\t5. Islamic Studies/Ethics\n\t6. English Language Skills\n\t7. Civics and Community Engagement\n\n");
        printf("Second semester courses:\n\t1. Linear Circuit Analysis\n\t2. Programming Fundamentals\n\t3. Engineering Workshop\n\t4. Linear Algebra and Differential Equation\n\t5. Ideology and Constitution of Pakistan\n\t6. Occupational Health and Safety\n\n");
        printf("Third semester courses:\n\t1. Data Structures and Algorithms\n\t2. Electronic Devices and Circuits\n\t3. Electrical Network Analysis\n\t4. Multivariable Calculus\n\t5. Complex Variables and Transform\n\n");
        printf("Fourth semester courses:\n\t1. Signals and Systems\n\t2. Digital Logic Design\n\t3. Probability and Random Processes\n\t4. Multi-Disciplinary Engineering Elective\n\t5. Electro Mechanical Systems\n\n");
        printf("Fifth semester courses:\n\t1. Microprocessor Interfacing and Programming\n\t2. Analogue and Digital Communication\n\t3. Electromagnetic Theory\n\t4. Technical Communication Skills\n\t5. Depth Core I\n\n");
        printf("Sixth semester courses:\n\t1. Power Distribution and Utilization\n\t2. Feedback Control Systems\n\t3. Engineering Economics\n\t4. Depth Core II\n\t5. Depth Elective III\n\n");
        printf("Seventh semester courses:\n\t1. Final Year Project - I\n\t2. Depth Elective IV\n\t3. Flexible Elective I\n\t4. Engineering Management\n\t5. Technical and Business Writing\n\n");
        printf("Eighth semester courses:\n\t1. Final Year Project - II\n\t2. Entrepreneurship\n\t3. Depth Elective V\n\t4. Flexible Elective II\n\t5. Flexible Elective III\n\n");



        break;
    case 3:
        printf("You are the student of EE.\n\n");
        printf("First semester courses:\n\t1. Psychology / Sociology\n\t2. Fundamentals of Accounting\n\t3. Business Math I\n\t4. Fundamentals of Management\n\t5. English - I\n\t6. Islamic Studies / Ethics\n\t7. Understanding Sirat-un-Nabi\n\n");
        printf("Second semester courses:\n\t1. Financial Accounting\n\t2. Data Analysis for Business I\n\t3. Marketing Management\n\t4. IT in Business\n\t5. English - II\n\t6. Pakistan Studies\n\n");
        printf("Third semester courses:\n\t1. Business Economics\n\t2. Critical Thinking\n\t3. Management Accounting\n\t4. Data Analysis for Business II\n\t5. Organizational Behaviour\n\t6. Civics and Community Engagement\n\t7. Understanding of Holy Quran I\n\n");
        printf("Fourth semester courses:\n\t1. Business Finance\n\t2. Environmental Science and Sustainability for Business\n\t3. Business Math - II\n\t4. Programming for Business\n\t5. Business Communication\n\t6. Ideology and Constitution of Pakistan\n\t7. Understanding of Holy Quran II\n\n");
        printf("Fifth semester courses:\n\t1. Consumer Behaviour\n\t2. Financial Management\n\t3. Operations Management\n\t4. Human Resource Management\n\t5. Advanced Business Communication\n\n");
        printf("Sixth semester courses:\n\t1. Management Information Systems\n\t2. Fundamentals of Business Analytics\n\t3. Digital Media Marketing\n\t4. Methods in Business Research\n\t5. Elective - I\n\n");
        printf("Seventh semester courses:\n\t1. Business Law\n\t2. Final Year Project - I\n\t3. Elective - II\n\t4. Elective - III\n\n");
        printf("Eighth semester courses (BBA):\n\t1. Strategic Management\n\t2. Entrepreneurship\n\t3. Final Year Project - II\n\t4. Elective - IV\n\t5. Elective - V\n\t6. Internship\n\n");

        break;
    
    default:
        break;
    }
 



    return 0;
}