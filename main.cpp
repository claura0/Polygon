#include "polygon.h"
#include "isotrapezoid.h"
#include "rectangle.h"
#include "rhombus.h"

#define MAX 100

int main() {

    int i = 0;
    int j;
    int n = 0;
    Polygon *mem[MAX];

    while ((n != 5) && (i < MAX)) {
        cout << "Choose an option:" << endl;
        cout << "1 - Create a rectangle" << endl;
        cout << "2 - Create a rhombus" << endl;
        cout << "3 - Create an isosceles trapezoid" << endl;
        cout << "4 - Draw" << endl;
        cout << "5 - Exit" << endl;
        scanf("%d", &n);

        switch (n) {
            case 1: {
                cout << "RECTANGLE" << endl;

                Rectangle *p;
                p = new Rectangle;

                float width = 0;
                float length = 0;

                cout << "Width:" << endl;
                scanf("%f", &width);
                cout << "Length:" << endl;
                scanf("%f", &length);
                p -> SetDim(width, length);

                mem[i] = p;
                i++;
                break;
            }


            case 2: {
                cout << "RHOMBUS" << endl;

                Rhombus *p;
                p = new Rhombus;

                float diagonalH = 0;
                float diagonalV = 0;

                cout << "Horizontal diagonal:" << endl;
                scanf("%f", &diagonalH);
                cout << "Vertical diagonal:" << endl;
                scanf("%f", &diagonalV);
                p -> SetDim(diagonalH,diagonalV);

                mem[i] = p;
                i++;
                break;
            }

            case 3: {
                cout << "ISOTRAPEZOID" << endl;

                IsoTrapezoid *p;
                p = new IsoTrapezoid;

                float topside = 0;
                float bottomside = 0;
                float height = 0;

                cout << "Top side:" << endl;
                scanf("%f", &topside);
                cout << "Bottom side:" << endl;
                scanf("%f", &bottomside);
                cout << "Height:" << endl;
                scanf("%f", &height);
                p -> SetDim(topside, bottomside, height);

                mem[i] = p;
                i++;
                break;
            }

            case 4: {
                for (j = 0; j < i; j++) {
                    mem[j]->Draw();
                }
                break;
            }

            case 5: {
                for (j = 0; j < i; j++) {
                    mem[j]->~Polygon();
                }
                break;
            }

            default: {
                cout << "Invalid option." << endl;
                break;
            }
        }
    }

    while (n != 5) {
            cout << "WARNING! Memory is full. You can still choose these options:" << endl;
            cout << "4 - Draw" << endl;
            cout << "5 - Exit" << endl;
            scanf("%d",&n);

            switch (n) {
                case 4: {

                    for (j = 0; j < MAX; j++) {
                        mem[j]->Draw();
                    }
                    break;
                }

                case 5: {
                    for (j = 0; j < MAX; j++) {
                        mem[j]->~Polygon();
                    }
                    break;
                }

                default:
                {
                    cout << "Invalid option." << endl;
                    break;
                }

            }
    }
    return 0;
}
