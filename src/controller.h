#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <iostream>

#include "model/model.h"

namespace s21 {
class Controller {
 public:
  Controller() : model_() {}
  Controller(const Model& m) : model_(m){};
  ~Controller() {}

  void Parser(const std::string& filename) { model_.ParseFile(filename); }

  size_t GetNumberVertices() const { return model_.GetNumberVertices(); }

  size_t GetNumberFacets() const { return model_.GetNumberFacets(); }

  void CenterVertices() { model_.CenterVertices(); }

  void InitialScale() { model_.InitialScale(); }

  void Shift(double x, double y, double z) { model_.Shift(x, y, z); }

  void Scale(double scale) { model_.Scale(scale); }

  void Rotate(double degrees, int ax) { model_.Rotate(degrees, ax); }

  std::vector<s21::Vertex> GetVertices() const { return model_.GetVertices(); }

  std::vector<unsigned int> GetFacets() const { return model_.GetFacets(); }

  // Для обнуления кол-ва вершин и рёбер перед открытием нового файла
  void SetNumberVertices(int number_vertices) {
    model_.SetNumberVertices(number_vertices);
  }

  void SetNumberFacets(int number_facets) {
    model_.SetNumberFacets(number_facets);
  }

  // Для очистки старой фигуры
  void ClearObj() { model_.ClearObj(); }

 private:
  Model model_;
};
}  // namespace s21

#endif  // SRC_CONTROLLER_H_
