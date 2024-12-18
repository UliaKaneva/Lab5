#include "classes.h"

bool compare_product(std::shared_ptr<Product> &product1, std::shared_ptr<Product> &product2) {
    return product1->get_category() < product1->get_category();
}

std::ostream &operator<<(std::ostream &stream, const Warehouse &warehouse) {
    stream << "Total Products: " << warehouse.productList.size() << "\n"
           << "Total Storage Cost: " << warehouse.all_value() << "$\n\n";
    warehouse.displayInventory();
    return stream;
}

Warehouse::product_ptr Warehouse::search_by_index(const int ID_find) {
    for (const auto &product: productList) {
        if (product->get_ID() == ID_find) {
            return product;
        }
    }
    return nullptr;

}

bool Warehouse::add_product(const Warehouse::product_ptr &product) {
    if (search_by_index(product->get_ID())) {
        return false;
    }
    productList.push_back(product);
    return true;
}

bool Warehouse::delete_product(const int ID_to_del) {
    auto it = std::remove_if(productList.begin(), productList.end(),
                             [ID_to_del](const product_ptr &p) { return p->get_ID() == ID_to_del; });
    if (it != productList.end()) {
        productList.erase(it);
        return true;
    }
    return false;
}

Warehouse::product_ptr_vector Warehouse::search_by_category(const std::string &category) const {
    product_ptr_vector res;
    for (const auto &product: productList) {
        if (product->get_category() == category) {
            res.push_back(product);
        }
    }
    return res;
}

double Warehouse::all_value() const {
    double sum = 0.0;
    for (const auto &product: productList) {
        sum += product->calculateStorageFee();
    }
    return sum;
}

Warehouse::product_ptr_vector Warehouse::getExpiringProducts(size_t days) {
    product_ptr_vector res;
    for (const auto &product: productList) {
        std::shared_ptr<PerishableProduct> p = std::dynamic_pointer_cast<PerishableProduct>(product);
        if (p && p->get_shelf_life() + days >= p->get_expirationDate()) {
            res.push_back(p);
        }
    }
    return res;
}

void Warehouse::displayInventory() const {
    std::string categories[] = {"Perishable Product", "Electronic Product", "Building Material"};
    for (const auto& category : categories) {
        product_ptr_vector products = search_by_category(category);
        for (const auto& product : products) {
            product->displayInfo();
            std::cout << "\n";
        }
    }
    std::cout << "-----------\n\n";
}

Warehouse &Warehouse::operator+=(Warehouse::product_ptr &product) {
    add_product(product);
    return *this;
}

Warehouse &Warehouse::operator-=(int ID_to_del) {
    delete_product(ID_to_del);
    return *this;
}

Warehouse::product_ptr Warehouse::operator[](int ID_index) {
    product_ptr res = search_by_index(ID_index);
    return res;
}

double Product::calculateStorageFee() const {
    return price * weight;
}

std::string Product::get_category() const {
    return "Product";
}

size_t Product::get_shelf_life() const {
    return shelf_life;
}

void Product::displayInfo() {
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Weight: " << weight << std::endl;
    std::cout << "Shelf life: " << shelf_life << std::endl;
}

int Product::get_ID() const {
    return ID;
}

double PerishableProduct::calculateStorageFee() const {
    return price * weight *
           (1.0 + ((double) ((shelf_life >= expirationDate) ? expirationDate : shelf_life)) / expirationDate);
}

std::string PerishableProduct::get_category() const {
    return "Perishable Product";
}

size_t PerishableProduct::get_expirationDate() const {
    return expirationDate;
}

void ElectronicProduct::displayInfo() {
    Product::displayInfo();
    std::cout << "Warranty period: " << warrantyPeriod << std::endl;
    std::cout << "Power rating: " << powerRating << std::endl;
}

std::string ElectronicProduct::get_category() const {
    return "Electronic Product";
}

double BuildingMaterial::calculateStorageFee() const {
    return Product::calculateStorageFee() * ((flammability) ? 2.0 : 1.0);
}

std::string BuildingMaterial::get_category() const {
    return "Building Material";
}
