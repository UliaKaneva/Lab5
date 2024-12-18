#include "classes.h"

int main() {
    std::shared_ptr<Product> perishableProduct = std::make_shared<PerishableProduct>(
            "Milk", 1, 1.5, 2.0, 7, 10
    );

    std::shared_ptr<Product> electronicProduct = std::make_shared<ElectronicProduct>(
            "Laptop", 2, 2.0, 1000.0, 365, 1, 50
    );

    std::shared_ptr<Product> buildingMaterial = std::make_shared<BuildingMaterial>(
            "Wood", 3, 10.0, 50.0, 365, 1
    );

    Warehouse warehouse;

    warehouse.add_product(electronicProduct);
    warehouse += perishableProduct;
    warehouse.add_product(buildingMaterial);

    std::cout << warehouse;

    std::cout << "Searching for Perishable Products:\n";
    auto perishableProducts = warehouse.search_by_category("Perishable Product");
    for (const auto &product : perishableProducts) {
        product->displayInfo();
        std::cout << "\n";
    }

    std::cout << "Deleting product with ID 2:\n";
    warehouse -= 2;

    std::cout << warehouse;

    std::cout << "Expiring Products in the next 5 days:\n";
    auto expiringProducts = warehouse.getExpiringProducts(5);
    for (const auto &product : expiringProducts) {
        product->displayInfo();
        std::cout << "\n";
    }

    return 0;
}