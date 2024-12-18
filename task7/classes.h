#ifndef LAB5_5_7_H
#define LAB5_5_7_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>


class Product {
protected:
    std::string name;
    int ID;
    double weight;
    double price;
    size_t shelf_life;
public:
    Product(const std::string &name_p, int ID_p, double weight_p, double value_p, size_t life) : name(name_p), ID(ID_p),
                                                                                                 weight(weight_p),
                                                                                                 price(value_p),
                                                                                                 shelf_life(life) {}

    Product(const Product &product) = default;

    Product &operator=(const Product &product) = default;

    virtual ~Product() = default;

    virtual double calculateStorageFee() const;

    virtual std::string get_category() const;

    size_t get_shelf_life() const;

    virtual void displayInfo();

    int get_ID() const;
};

class PerishableProduct : public Product {
protected:
    unsigned int expirationDate;
public:
    double calculateStorageFee() const override;

    PerishableProduct(const std::string &name_p, int ID_p, double weight_p, double value_p, size_t life,
                      unsigned int expirationDate) : Product(name_p, ID_p, weight_p, value_p, life),
                                                     expirationDate(expirationDate) {}

    PerishableProduct(const PerishableProduct &pp) = default;

    PerishableProduct &operator=(const PerishableProduct &pp) = default;

    ~PerishableProduct() override = default;

    std::string get_category() const override;

    size_t get_expirationDate() const;
};

class ElectronicProduct : public Product {
protected:
    bool warrantyPeriod;
    unsigned int powerRating;
public:
    ElectronicProduct(const std::string &name_p, int ID_p, double weight_p, double value_p, size_t life, bool wP,
                      unsigned int pR) : Product(name_p, ID_p, weight_p, value_p, life), warrantyPeriod(wP),
                                         powerRating(pR) {}

    ElectronicProduct(const ElectronicProduct &ep) = default;

    ElectronicProduct &operator=(const ElectronicProduct &ep) = default;

    ~ElectronicProduct() override = default;

    void displayInfo() override;

    std::string get_category() const override;
};

class BuildingMaterial : public Product {
protected:
    bool flammability;
public:
    BuildingMaterial(const std::string &name_p, int ID_p, double weight_p, double value_p, size_t life, bool fb)
            : Product(name_p, ID_p, weight_p, value_p, life), flammability(fb) {}

    BuildingMaterial(const BuildingMaterial &ep) = default;

    BuildingMaterial &operator=(const BuildingMaterial &ep) = default;

    ~BuildingMaterial() override = default;

    double calculateStorageFee() const override;

    std::string get_category() const override;
};

bool compare_product(std::shared_ptr<Product> &product1, std::shared_ptr<Product> &product2);

class Warehouse {
    using product_ptr = std::shared_ptr<Product>;
    using product_ptr_vector = std::vector<product_ptr>;

    product_ptr_vector productList;

    product_ptr search_by_index(int ID_find);

public:
    bool add_product(const product_ptr &product);

    bool delete_product(int ID_to_del);

    product_ptr_vector search_by_category(const std::string &category) const;

    double all_value() const;

    product_ptr_vector getExpiringProducts(size_t days);

    void displayInventory() const;

    Warehouse &operator+=(product_ptr &product);

    Warehouse &operator-=(int ID_to_del);

    product_ptr operator[](int ID_index);

    friend std::ostream &operator<<(std::ostream &stream, const Warehouse &warehouse);

};


#endif //LAB5_5_7_H
