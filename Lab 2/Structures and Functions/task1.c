#include <stdio.h>
struct Paratha {
    int quantity;
    float unit_price;
};
struct Vegetable {
    int quantity;
    float unit_price;
};
struct MineralWater {
    int quantity;
    float unit_price;
};

int main() {
    struct Paratha paratha;
    struct Vegetable vegetable;
    struct MineralWater water;
    int people;
    float bill, individual;


    printf("Quantity Of Paratha: ");
    scanf("%d", &paratha.quantity);
    printf("Unit Price: ");
    scanf("%f", &paratha.unit_price);
    printf("Quantity Of Vegetables: ");
    scanf("%d", &vegetable.quantity);
    printf("Unit Price: ");
    scanf("%f", &vegetable.unit_price);
    printf("Quantity Of Mineral Water: ");
    scanf("%d", &water.quantity);
    printf("Unit Price: ");
    scanf("%f", &water.unit_price);
    printf("Number of People: ");
    scanf("%d", &people);

    bill = (paratha.quantity * paratha.unit_price)+ (vegetable.quantity * vegetable.unit_price) +(water.quantity * water.unit_price);

    individual = bill / people;
    printf("Individual people will pay: %.2f tk\n", individual);

    return 0;
}
