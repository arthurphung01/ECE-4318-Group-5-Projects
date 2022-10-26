#include <iostream>
using namespace std;

int max(int m, int n) 
{  
    return (m > n)? m: n; 
    
    
}

int *add(int A[], int B[], int m, int n)
{
   int size = max(m, n); //returns the largest of m and n 
   int *sum = new int[size];
 
   // Initialize the product polynomial
   for (int i = 0; i<m; i++)
     sum[i] = A[i];
 
   // Take ever term of first polynomial and add them to the other polynomial
   for (int i=0; i<n; i++)
       sum[i] += B[i];
 
   return sum;
}

int *sub(int A[], int B[], int m, int n)
{
    int size = max(m, n); 
   int *diff = new int[size];
 
   for (int i = 0; i<m; i++)
     diff[i] = A[i];
 
   // Take ever term of first polynomial and subtract them to the other polynomial 
   for (int i=0; i<n; i++)
       diff[i] += B[i];
 
   return diff; 
    
}

int *multiply(int A[], int B[], int m, int n)
{
   int *prod = new int[m+n-1];
  
   // Initialize the product polynomial
   for (int i = 0; i<m+n-1; i++)
     prod[i] = 0;
  
   // Multiply two polynomials term by term
  
   // Take ever term of first polynomial
   for (int i=0; i<m; i++)
   {
     // Multiply the current term of first polynomial
     // with every term of second polynomial.
     for (int j=0; j<n; j++)
         prod[i+j] += A[i]*B[j];
   }
  
   return prod;
}

// Function to print a polynomial
void printPoly(int poly[], int n)
{
    for (int i=0; i<n; i++)
    {
       cout << poly[i];
       if (i != 0)
        cout << "x^" << i ;
       if (i != n-1)
       cout << " + ";
    }
}

//-------Division Functions-----------
//Using a Linked List

struct Node {
    float coeff;
    int pow;
    struct Node* next;
};
 
// Function to create new node
void create_node(float x, int y,
                 struct Node** temp)
{
    struct Node *r, *z;
    z = *temp;
 
    // If temp is NULL
    if (z == NULL) {
 
        r = (struct Node*)malloc(
            sizeof(struct Node));
 
        // Update coefficient and
        // power in the LL z
        r->coeff = x;
        r->pow = y;
        *temp = r;
        r->next = (struct Node*)malloc(
            sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
 
    // Otherwise
    else {
        r->coeff = x;
        r->pow = y;
        r->next = (struct Node*)malloc(
            sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
}
 
// Function to create a LL that stores
// the value of the quotient while
// performing polynomial division
void store_quotient(float mul_c, int diff,
                    struct Node* quo)
{
    // Till quo is non-empty
    while (quo->next != NULL) {
        quo = quo->next;
    }
 
    // Update powers and coefficient
    quo->pow = diff;
    quo->coeff = mul_c;
    quo->next = (struct Node*)malloc(
        sizeof(struct Node));
    quo = quo->next;
    quo->next = NULL;
}
 
// Function to create a new polynomial
// whenever subtraction is performed
// in polynomial division
void formNewPoly(int diff, float mul_c,
                 struct Node* poly)
{
    // Till poly is not empty
    while (poly->next != NULL) {
        poly->pow += diff;
        poly->coeff *= mul_c;
        poly = poly->next;
    }
}
 
// Function to copy one polynomial
// into another linkedlist
void copyList(struct Node* r,
              struct Node** copy)
{
    // Copy the values of r in the
    // polynomial copy
    while (r != NULL) {
 
        struct Node* z
            = (struct Node*)malloc(
                sizeof(struct Node));
 
        // Store coefficient and power
        z->coeff = r->coeff;
        z->pow = r->pow;
        z->next = NULL;
 
        struct Node* dis = *copy;
        if (dis == NULL) {
            *copy = z;
        }
        else {
            while (dis->next != NULL) {
                dis = dis->next;
            }
            dis->next = z;
        }
        r = r->next;
    }
}
 
// Function to subtract two polynomial for division 
void polySub(struct Node* poly1,
             struct Node* poly2,
             struct Node* poly)
{
 
    // Compute until poly1 and poly2 is empty
    while (poly1->next && poly2->next) {
 
        // If power of 1st polynomial
        // > 2nd, then store 1st as
        // it is and move its pointer
        if (poly1->pow > poly2->pow) {
 
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
            poly->next
                = (struct Node*)malloc(
                    sizeof(struct Node));
            poly = poly->next;
            poly->next = NULL;
        }
 
        // If power of 2nd polynomial >
        // 1st then store 2nd as it is
        // and move its pointer
        else if (poly1->pow < poly2->pow) {
 
            poly->pow = poly2->pow;
            poly->coeff = -1 * poly2->coeff;
            poly2 = poly2->next;
            poly->next
                = (struct Node*)malloc(
                    sizeof(struct Node));
            poly = poly->next;
            poly->next = NULL;
        }
 
        // If power of both polynomial
        // is same then subtract their
        // coefficients
        else {
 
            if ((poly1->coeff
                 - poly2->coeff)
                != 0) {
 
                poly->pow = poly1->pow;
                poly->coeff = (poly1->coeff
                               - poly2->coeff);
 
                poly->next = (struct Node*)malloc(
                    sizeof(struct Node));
                poly = poly->next;
                poly->next = NULL;
            }
 
            // Update the pointers
            // poly1 and poly2
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
 
    // Add the remaining value of polynomials
    while (poly1->next || poly2->next) {
 
        // If poly1 exists
        if (poly1->next) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
 
        // If poly2 exists
        if (poly2->next) {
            poly->pow = poly2->pow;
            poly->coeff = -1 * poly2->coeff;
            poly2 = poly2->next;
        }
 
        // Add the new node to poly
        poly->next
            = (struct Node*)malloc(
                sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
}
 
// Function to display linked list
void show(struct Node* node)
{
    int count = 0;
    while (node->next != NULL
           && node->coeff != 0) {
 
        // If count is non-zero, then
        // print the positive value
        if (count == 0)
            cout << node->coeff;
 
        // Otherwise
        else
            cout << abs(node->coeff);
        count++;
 
        // Print polynomial power
        if (node->pow != 0)
            cout << "x^" << node->pow;
        node = node->next;
 
        if (node->next != NULL)
 
            // If coeff of next term
            // > 0 then next sign will
            // be positive else negative
            if (node->coeff > 0)
            {
                cout << " + ";
            }
            else
            {cout << " - ";}
    }
 
    cout << "\n";
}
 
// Function to divide two polynomials
void divide_poly(struct Node* poly1,
                 struct Node* poly2)
{
    // Initialize Remainder and Quotient
    struct Node *rem = NULL, *quo = NULL;
 
    quo = (struct Node*)malloc(
        sizeof(struct Node));
    quo->next = NULL;
 
    struct Node *q = NULL, *r = NULL;
 
    // Copy poly1, i.e., dividend to q
    copyList(poly1, &q);
 
    // Copy poly, i.e., divisor to r
    copyList(poly2, &r);
 
    // Perform polynomial subtraction till
    // highest power of q > highest power of divisor
    while (q != NULL
           && (q->pow >= poly2->pow)) {
 
        // difference of power
        int diff = q->pow - poly2->pow;
 
        float mul_c = (q->coeff
                       / poly2->coeff);
 
        // Stores the quotient node
        store_quotient(mul_c, diff,
                       quo);
 
        struct Node* q2 = NULL;
 
        // Copy one LL in another LL
        copyList(r, &q2);
 
        // formNewPoly forms next value
        // of q after performing the
        // polynomial subtraction
        formNewPoly(diff, mul_c, q2);
 
        struct Node* store = NULL;
        store = (struct Node*)malloc(
            sizeof(struct Node));
 
        // Perform polynomial subtraction
        polySub(q, q2, store);
 
        // Now change value of q to the
        // subtracted value i.e., store
        q = store;
        free(q2);
    }
 
    // Print the quotient
    cout << "Quotient: ";
    show(quo);
 
    // Print the remainder
    cout << "Remainder: ";
    rem = q;
    show(rem);
}

//------------Subtraction Functions-----------
//Regualar Subtraction 

int *subtraction(int A[], int B[], int m, int n) {
    int max, i;
    max = (m > n) ? m : n;
    int *sub = new int[max + 1];
    if (m == n) {
        for (i = m; i >= 0; i--)
            sub[i] = A[i] - B[i];
    }

    if (m > n) {
        for (i = m; i > n; i--)
            sub[i] = A[i];
        for (i = n; i >= 0; i--)
            sub[i] = A[i] - B[i];
    }

    if (m < n) {
        for (i = n; i > m; i--)
            sub[i] = -B[i];
        for (i = m; i >= 0; i--)
            sub[i] = A[i] - B[i];
    }
    return sub;
}

int main()
{
    // -----------Addition, Subtraction, Multiplication----------------
    // Ordered from lowest to higest degree
    //Polynomial 1: 4x^3 + 3x^2 + 1x^1 + 8x^0
    int A[] = {8, 1, 3, 4};
 
    //Polynmial 2: 3x^3+ 3x^2 + 1x^1 + 0x^0
    int B[] = {0,1,3,3};
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);
 
    cout << "First polynomial is \n";
    printPoly(A, m);
    cout << "\n";
    cout << "\nSecond polynomial is \n";
    printPoly(B, n);
    cout << "\n";
 
    int *prod = multiply(A, B, m, n);
    int *sum = add(A, B, m, n);
    int *sub = subtraction(A,B,m,n);
  
    int size = max(m, n);

 
    cout << "\nsum polynomial is \n";
    printPoly(sum, size);
    cout << "\n";
    
    cout << "\ndiff polynomial is \n";
    printPoly(sub, size);
    cout << "\n";
    
    
    cout <<endl<< "Product polynomial is " << "\n";
    printPoly(prod, m+n-1);
    cout << "\n\n";
    //------------------Division----------------------
    
    struct Node* poly1 = NULL;
    struct Node *poly2 = NULL, *poly = NULL;
 
    // Create 1st Polynomial (Dividend): (1+x)^10
    //First argument is coefficient, second is degree, third is the polynomial
    // create_node(1.0, 10, &poly1);
    // create_node(10.0, 9, &poly1);
    // create_node(45.0, 8, &poly1);
    // create_node(120.0, 7, &poly1);
    // create_node(210.0, 6, &poly1);
    // create_node(252.0, 5, &poly1);
    // create_node(210.0, 4, &poly1);
    // create_node(120.0, 3, &poly1);
    // create_node(45.0, 2, &poly1);
    // create_node(10.0, 1, &poly1);
    // create_node(1.0, 0, &poly1);

    //Dividend: 4x^3 + 3x^2 + 1x^1 + 8x^0
    create_node(4.0, 3, &poly1);
    create_node(3.0, 2, &poly1);
    create_node(1.0, 1, &poly1);
    create_node(8.0, 0, &poly1);
 
    // Create 2nd Polynomial (Divisor): (1+x)^3
    // create_node(1.0, 3, &poly2);
    // create_node(3.0, 2, &poly2);
    // create_node(3.0, 1, &poly2);
    // create_node(1.0, 0, &poly2);

    //Divisor: 3x^3+ 3x^2 + 1x^1 + 0x^0
    create_node(3.0, 3, &poly2);
    create_node(3.0, 2, &poly2);
    create_node(1.0, 1, &poly2);
    create_node(0.0, 0, &poly2);

    divide_poly(poly1, poly2);
    
    cout << "\n";

 
    return 0;
}
