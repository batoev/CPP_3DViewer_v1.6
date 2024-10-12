#include <gtest/gtest.h>

#include "../controller.h"
#include "../model/model.h"

#define S21_EPS 1e-6

void PrintFacets(s21::Controller x) {
  if (x.GetFacets().empty()) {
    std::cout << "Empty" << std::endl;
  } else {
    for (size_t i = 0; i < x.GetFacets().size(); i++) {
      std::cout << x.GetFacets()[i] << " ";
    }
    std::cout << std::endl;
  }
}

TEST(Parser, Test_1) {
  s21::Controller controller;
  std::string filename = "";
  EXPECT_THROW(controller.Parser(filename), std::runtime_error);
}

TEST(Parser, Test_2) {
  std::string filename = "./objects/test.obj";
  s21::Controller controller;
  controller.Parser(filename);
  EXPECT_EQ(controller.GetNumberVertices(), 8);
  EXPECT_EQ(controller.GetNumberFacets(), 12);
  EXPECT_EQ(controller.GetFacets().size(), 72);
  EXPECT_EQ(controller.GetFacets()[0], 0);
  EXPECT_EQ(controller.GetFacets()[1], 6);
  EXPECT_EQ(controller.GetFacets()[2], 6);
  EXPECT_EQ(controller.GetFacets()[3], 4);
  EXPECT_EQ(controller.GetFacets()[4], 4);
  EXPECT_EQ(controller.GetFacets()[5], 0);
  EXPECT_EQ(controller.GetFacets()[6], 0);
  EXPECT_EQ(controller.GetFacets()[7], 2);
  EXPECT_EQ(controller.GetFacets()[8], 2);
  EXPECT_EQ(controller.GetFacets()[9], 6);
  EXPECT_EQ(controller.GetFacets()[10], 6);
  EXPECT_EQ(controller.GetFacets()[11], 0);
  EXPECT_EQ(controller.GetFacets()[12], 0);
  EXPECT_EQ(controller.GetFacets()[13], 3);
  EXPECT_EQ(controller.GetFacets()[14], 3);
  EXPECT_EQ(controller.GetFacets()[15], 2);
  EXPECT_EQ(controller.GetFacets()[16], 2);
  EXPECT_EQ(controller.GetFacets()[17], 0);
  EXPECT_EQ(controller.GetFacets()[18], 0);
  EXPECT_EQ(controller.GetFacets()[19], 1);
  EXPECT_EQ(controller.GetFacets()[20], 1);
  EXPECT_EQ(controller.GetFacets()[21], 3);
  EXPECT_EQ(controller.GetFacets()[22], 3);
  EXPECT_EQ(controller.GetFacets()[23], 0);
  EXPECT_EQ(controller.GetFacets()[24], 2);
  EXPECT_EQ(controller.GetFacets()[25], 7);
  EXPECT_EQ(controller.GetFacets()[26], 7);
  EXPECT_EQ(controller.GetFacets()[27], 6);
  EXPECT_EQ(controller.GetFacets()[28], 6);
  EXPECT_EQ(controller.GetFacets()[29], 2);
  EXPECT_EQ(controller.GetFacets()[30], 2);
  EXPECT_EQ(controller.GetFacets()[31], 3);
  EXPECT_EQ(controller.GetFacets()[32], 3);
  EXPECT_EQ(controller.GetFacets()[33], 7);
  EXPECT_EQ(controller.GetFacets()[34], 7);
  EXPECT_EQ(controller.GetFacets()[35], 2);
  EXPECT_EQ(controller.GetFacets()[36], 4);
  EXPECT_EQ(controller.GetFacets()[37], 6);
  EXPECT_EQ(controller.GetFacets()[38], 6);
  EXPECT_EQ(controller.GetFacets()[39], 7);
  EXPECT_EQ(controller.GetFacets()[40], 7);
  EXPECT_EQ(controller.GetFacets()[41], 4);
  EXPECT_EQ(controller.GetFacets()[42], 4);
  EXPECT_EQ(controller.GetFacets()[43], 7);
  EXPECT_EQ(controller.GetFacets()[44], 7);
  EXPECT_EQ(controller.GetFacets()[45], 5);
  EXPECT_EQ(controller.GetFacets()[46], 5);
  EXPECT_EQ(controller.GetFacets()[47], 4);
  EXPECT_EQ(controller.GetFacets()[48], 0);
  EXPECT_EQ(controller.GetFacets()[49], 4);
  EXPECT_EQ(controller.GetFacets()[50], 4);
  EXPECT_EQ(controller.GetFacets()[51], 5);
  EXPECT_EQ(controller.GetFacets()[52], 5);
  EXPECT_EQ(controller.GetFacets()[53], 0);
  EXPECT_EQ(controller.GetFacets()[54], 0);
  EXPECT_EQ(controller.GetFacets()[55], 5);
  EXPECT_EQ(controller.GetFacets()[56], 5);
  EXPECT_EQ(controller.GetFacets()[57], 1);
  EXPECT_EQ(controller.GetFacets()[58], 1);
  EXPECT_EQ(controller.GetFacets()[59], 0);
  EXPECT_EQ(controller.GetFacets()[60], 1);
  EXPECT_EQ(controller.GetFacets()[61], 5);
  EXPECT_EQ(controller.GetFacets()[62], 5);
  EXPECT_EQ(controller.GetFacets()[63], 7);
  EXPECT_EQ(controller.GetFacets()[64], 7);
  EXPECT_EQ(controller.GetFacets()[65], 1);
  EXPECT_EQ(controller.GetFacets()[66], 1);
  EXPECT_EQ(controller.GetFacets()[67], 7);
  EXPECT_EQ(controller.GetFacets()[68], 7);
  EXPECT_EQ(controller.GetFacets()[69], 3);
  EXPECT_EQ(controller.GetFacets()[70], 3);
  EXPECT_EQ(controller.GetFacets()[71], 1);
}

TEST(Controller_Scale, Test_1) {
  std::string filename = "./objects/test.obj";
  s21::Controller controller;
  controller.Parser(filename);
  size_t n = controller.GetVertices().size();
  double *arr_x = nullptr;
  double *arr_y = nullptr;
  double *arr_z = nullptr;
  arr_x = new double[n];
  arr_y = new double[n];
  arr_z = new double[n];
  for (size_t i = 0; i < n; ++i) {
    arr_x[i] = controller.GetVertices()[i].x;
    arr_y[i] = controller.GetVertices()[i].y;
    arr_z[i] = controller.GetVertices()[i].z;
  }
  int x = 2;
  controller.Scale(x);
  for (size_t i = 0; i < n; ++i) {
    EXPECT_EQ(controller.GetVertices()[i].x, arr_x[i] * x);
    EXPECT_EQ(controller.GetVertices()[i].y, arr_y[i] * x);
    EXPECT_EQ(controller.GetVertices()[i].z, arr_z[i] * x);
  }
}

TEST(Controller_Scale, Test_2) {
  std::string filename = "./objects/test.obj";
  s21::Controller controller;
  controller.Parser(filename);
  size_t n = controller.GetVertices().size();
  double *arr_x = nullptr;
  double *arr_y = nullptr;
  double *arr_z = nullptr;
  arr_x = new double[n];
  arr_y = new double[n];
  arr_z = new double[n];
  for (size_t i = 0; i < n; ++i) {
    arr_x[i] = controller.GetVertices()[i].x;
    arr_y[i] = controller.GetVertices()[i].y;
    arr_z[i] = controller.GetVertices()[i].z;
  }
  int x = 5;
  controller.Scale(x);
  for (size_t i = 0; i < n; ++i) {
    EXPECT_EQ(controller.GetVertices()[i].x, arr_x[i] * x);
    EXPECT_EQ(controller.GetVertices()[i].y, arr_y[i] * x);
    EXPECT_EQ(controller.GetVertices()[i].z, arr_z[i] * x);
  }
}

TEST(Controller_Shift, Test_1) {
  std::string filename = "./objects/test.obj";
  s21::Controller controller;
  controller.Parser(filename);
  size_t n = controller.GetVertices().size();
  double *arr_x = nullptr;
  double *arr_y = nullptr;
  double *arr_z = nullptr;
  arr_x = new double[n];
  arr_y = new double[n];
  arr_z = new double[n];
  for (size_t i = 0; i < n; ++i) {
    arr_x[i] = controller.GetVertices()[i].x;
    arr_y[i] = controller.GetVertices()[i].y;
    arr_z[i] = controller.GetVertices()[i].z;
  }
  int x = 5, y = 3, z = -7;
  controller.Shift(x, y, z);
  for (size_t i = 0; i < n; ++i) {
    EXPECT_EQ(controller.GetVertices()[i].x, arr_x[i] + x);
    EXPECT_EQ(controller.GetVertices()[i].y, arr_y[i] + y);
    EXPECT_EQ(controller.GetVertices()[i].z, arr_z[i] + z);
  }
}

TEST(Controller_Shift, Test_2) {
  std::string filename = "./objects/test.obj";
  s21::Controller controller;
  controller.Parser(filename);
  size_t n = controller.GetVertices().size();
  double *arr_x = nullptr;
  double *arr_y = nullptr;
  double *arr_z = nullptr;
  arr_x = new double[n];
  arr_y = new double[n];
  arr_z = new double[n];
  for (size_t i = 0; i < n; ++i) {
    arr_x[i] = controller.GetVertices()[i].x;
    arr_y[i] = controller.GetVertices()[i].y;
    arr_z[i] = controller.GetVertices()[i].z;
  }
  int x = 24.05, y = 19.88, z = 5;
  controller.Shift(x, y, z);
  for (size_t i = 0; i < n; ++i) {
    EXPECT_NEAR(controller.GetVertices()[i].x, arr_x[i] + x, S21_EPS);
    EXPECT_NEAR(controller.GetVertices()[i].y, arr_y[i] + y, S21_EPS);
    EXPECT_NEAR(controller.GetVertices()[i].z, arr_z[i] + z, S21_EPS);
  }
}

TEST(Controller_Rotate, Test_1) {
  std::string filename = "./objects/test.obj";
  s21::Controller controller;
  controller.Parser(filename);
  size_t n = controller.GetVertices().size();
  double *arr_x = nullptr;
  double *arr_y = nullptr;
  double *arr_z = nullptr;
  arr_x = new double[n];
  arr_y = new double[n];
  arr_z = new double[n];
  for (size_t i = 0; i < n; ++i) {
    arr_x[i] = controller.GetVertices()[i].x;
    arr_y[i] = controller.GetVertices()[i].y;
    arr_z[i] = controller.GetVertices()[i].z;
  }
  double degrees = 24.05;
  int ax = 0;
  controller.Rotate(degrees, ax);
  for (size_t i = 0; i < n; ++i) {
    EXPECT_NEAR(controller.GetVertices()[i].x, arr_x[i], S21_EPS);
    EXPECT_NEAR(controller.GetVertices()[i].y,
                arr_y[i] * cos(degrees * M_PI / 180) -
                    arr_z[i] * sin(degrees * M_PI / 180),
                S21_EPS);
    EXPECT_NEAR(controller.GetVertices()[i].z,
                arr_y[i] * sin(degrees * M_PI / 180) +
                    arr_z[i] * cos(degrees * M_PI / 180),
                S21_EPS);
  }
}

TEST(Controller_Rotate, Test_2) {
  std::string filename = "./objects/test.obj";
  s21::Controller controller;
  controller.Parser(filename);
  size_t n = controller.GetVertices().size();
  double *arr_x = nullptr;
  double *arr_y = nullptr;
  double *arr_z = nullptr;
  arr_x = new double[n];
  arr_y = new double[n];
  arr_z = new double[n];
  for (size_t i = 0; i < n; ++i) {
    arr_x[i] = controller.GetVertices()[i].x;
    arr_y[i] = controller.GetVertices()[i].y;
    arr_z[i] = controller.GetVertices()[i].z;
  }
  double degrees = 24.05;
  int ax = 1;
  controller.Rotate(degrees, ax);
  for (size_t i = 0; i < n; ++i) {
    EXPECT_NEAR(controller.GetVertices()[i].x,
                arr_x[i] * cos(degrees * M_PI / 180) +
                    arr_z[i] * sin(degrees * M_PI / 180),
                S21_EPS);
    EXPECT_NEAR(controller.GetVertices()[i].y, arr_y[i], S21_EPS);
    EXPECT_NEAR(controller.GetVertices()[i].z,
                -arr_x[i] * sin(degrees * M_PI / 180) +
                    arr_z[i] * cos(degrees * M_PI / 180),
                S21_EPS);
  }
}

TEST(Controller_Rotate, Test_3) {
  std::string filename = "./objects/test.obj";
  s21::Controller controller;
  controller.Parser(filename);
  size_t n = controller.GetVertices().size();
  double *arr_x = nullptr;
  double *arr_y = nullptr;
  double *arr_z = nullptr;
  arr_x = new double[n];
  arr_y = new double[n];
  arr_z = new double[n];
  for (size_t i = 0; i < n; ++i) {
    arr_x[i] = controller.GetVertices()[i].x;
    arr_y[i] = controller.GetVertices()[i].y;
    arr_z[i] = controller.GetVertices()[i].z;
  }
  double degrees = 24.05;
  int ax = 3;
  controller.Rotate(degrees, ax);
  for (size_t i = 0; i < n; ++i) {
    EXPECT_NEAR(controller.GetVertices()[i].x,
                arr_x[i] * cos(degrees * M_PI / 180) -
                    arr_y[i] * sin(degrees * M_PI / 180),
                S21_EPS);
    EXPECT_NEAR(controller.GetVertices()[i].y,
                arr_x[i] * sin(degrees * M_PI / 180) +
                    arr_y[i] * cos(degrees * M_PI / 180),
                S21_EPS);
    EXPECT_NEAR(controller.GetVertices()[i].z, arr_z[i], S21_EPS);
  }
}

TEST(ScanLineF, Test_1) {
  std::string line = " 3/3/3";
  int vertices_per_facet = 0;
  std::vector<int> vertices_ids;

  s21::Model model;
  model.ScanLineF(line, &vertices_per_facet, vertices_ids);

  EXPECT_EQ(vertices_per_facet, 1);
  ASSERT_EQ(vertices_ids.size(), 1);
  EXPECT_EQ(vertices_ids[0], 3);
}

TEST(ScanLineF, Test_2) {
  std::string line = " 5//3 9//2";
  int vertices_per_facet = 0;
  std::vector<int> vertices_ids;

  s21::Model model;
  model.ScanLineF(line, &vertices_per_facet, vertices_ids);

  EXPECT_EQ(vertices_per_facet, 2);
  ASSERT_EQ(vertices_ids.size(), 2);
  EXPECT_EQ(vertices_ids[0], 5);
  EXPECT_EQ(vertices_ids[1], 9);
}

TEST(ScanLineF, Test_3) {
  std::string line = " 8 4 2";
  int vertices_per_facet = 0;
  std::vector<int> vertices_ids;

  s21::Model model;
  model.ScanLineF(line, &vertices_per_facet, vertices_ids);

  EXPECT_EQ(vertices_per_facet, 3);
  ASSERT_EQ(vertices_ids.size(), 3);
  EXPECT_EQ(vertices_ids[0], 8);
  EXPECT_EQ(vertices_ids[1], 4);
  EXPECT_EQ(vertices_ids[2], 2);
}

TEST(ScanLineF, Test_4) {
  std::string line = " 8/2 2/5     ";
  int vertices_per_facet = 0;
  std::vector<int> vertices_ids;

  s21::Model model;
  model.ScanLineF(line, &vertices_per_facet, vertices_ids);

  EXPECT_EQ(vertices_per_facet, 2);
  ASSERT_EQ(vertices_ids.size(), 2);
  EXPECT_EQ(vertices_ids[0], 8);
  EXPECT_EQ(vertices_ids[1], 2);
}

TEST(ScanLineF, Test_5) {
  std::string line = "1/2/3 4/5/6";
  int vertices_per_facet = 0;
  std::vector<int> vertices_ids;

  s21::Model model;
  model.ScanLineF(line, &vertices_per_facet, vertices_ids);

  EXPECT_EQ(vertices_per_facet, 2);
  ASSERT_EQ(vertices_ids.size(), 2);
  EXPECT_EQ(vertices_ids[0], 1);
  EXPECT_EQ(vertices_ids[1], 4);
}

TEST(ScanLineF, Test_6) {
  std::string line = " 5//3 9//4 3//2 -4//5";
  int vertices_per_facet = 0;
  std::vector<int> vertices_ids;

  s21::Model model;
  model.ScanLineF(line, &vertices_per_facet, vertices_ids);

  EXPECT_EQ(vertices_per_facet, 4);
  ASSERT_EQ(vertices_ids.size(), 4);
  EXPECT_EQ(vertices_ids[0], 5);
  EXPECT_EQ(vertices_ids[1], 9);
  EXPECT_EQ(vertices_ids[2], 3);
  EXPECT_EQ(vertices_ids[3], -4);
}

TEST(ParseLineF, Test_1) {
  std::string line = "8 4 2";
  s21::Model model;
  model.SetNumberVertices(10);  // чтобы избежать ошибки
  model.ParseLineF(line);
  EXPECT_EQ(model.GetNumberFacets(), 1);
  EXPECT_EQ(model.GetFacets()[0], 7);
  EXPECT_EQ(model.GetFacets()[1], 3);
  EXPECT_EQ(model.GetFacets()[2], 3);
  EXPECT_EQ(model.GetFacets()[3], 1);
  EXPECT_EQ(model.GetFacets()[4], 1);
  EXPECT_EQ(model.GetFacets()[5], 7);
  EXPECT_EQ(model.GetFacets().size(), 6);
}

TEST(ParseLineF, Test_2) {
  std::string line = "8//2 -4 2";
  s21::Model model;
  model.SetNumberVertices(10);  // чтобы избежать ошибки
  model.ParseLineF(line);
  EXPECT_EQ(model.GetNumberFacets(), 1);
  EXPECT_EQ(model.GetFacets()[0], 7);
  EXPECT_EQ(model.GetFacets()[1], 6);  // 10 -4 = 6
  EXPECT_EQ(model.GetFacets()[2], 6);  // 10 -4 = 6
  EXPECT_EQ(model.GetFacets()[3], 1);
  EXPECT_EQ(model.GetFacets()[4], 1);
  EXPECT_EQ(model.GetFacets()[5], 7);
  EXPECT_EQ(model.GetFacets().size(), 6);
}

TEST(ParseLineF, Test_3) {
  std::string line = "abc5/2/3";
  s21::Model model;
  model.SetNumberVertices(10);  // чтобы избежать ошибки
  model.ParseLineF(line);
  // EXPECT_THROW(model.ParseLineF(line), std::runtime_error);
  EXPECT_EQ(model.GetNumberFacets(), 0);
  EXPECT_EQ(model.GetFacets().size(), 0);
}

TEST(ParseLineV, Test_1) {
  std::string line_1 = "1  2  3";
  std::string line_2 = "1.2  -3.4  5.6";
  std::string line_3 = "-7.8  9.1  -2.3";
  std::string line_4 = "-4.5  6.7  8.9";
  s21::Model model;
  model.ParseLineV(line_1);
  model.ParseLineV(line_2);
  model.ParseLineV(line_3);
  model.ParseLineV(line_4);

  // model.PrintVertices();

  EXPECT_EQ(model.GetVertices()[0].x, 1.0);
  EXPECT_EQ(model.GetVertices()[0].y, 2.0);
  EXPECT_EQ(model.GetVertices()[0].z, 3.0);
  EXPECT_EQ(model.GetVertices()[1].x, 1.2);
  EXPECT_EQ(model.GetVertices()[1].y, -3.4);
  EXPECT_EQ(model.GetVertices()[1].z, 5.6);
  EXPECT_EQ(model.GetVertices()[2].x, -7.8);
  EXPECT_EQ(model.GetVertices()[2].y, 9.1);
  EXPECT_EQ(model.GetVertices()[2].z, -2.3);
  EXPECT_EQ(model.GetVertices()[3].x, -4.5);
  EXPECT_EQ(model.GetVertices()[3].y, 6.7);
  EXPECT_EQ(model.GetVertices()[3].z, 8.9);
  EXPECT_EQ(model.NumberVertices(), 4);
  EXPECT_EQ(model.GetNumberVertices(), 4);
}

TEST(FindMaxMinValues, Test_1) {
  std::string line_1 = "1.5  2.5  3.5";
  std::string line_2 = "4.5  5.5  6.5";
  std::string line_3 = "7.5  8.5  9.5";
  s21::Model model;
  model.ParseLineV(line_1);
  model.ParseLineV(line_2);
  model.ParseLineV(line_3);
  double x_min = 0, x_max = 0, y_min = 0, y_max = 0, z_min = 0, z_max = 0;
  model.FindMaxMinValues(&x_min, &x_max, &y_min, &y_max, &z_min, &z_max);

  EXPECT_EQ(x_min, 1.5);
  EXPECT_EQ(x_max, 7.5);
  EXPECT_EQ(y_min, 2.5);
  EXPECT_EQ(y_max, 8.5);
  EXPECT_EQ(z_min, 3.5);
  EXPECT_EQ(z_max, 9.5);
}

TEST(Shift, Test_1) {
  std::string line_1 = "1.5  2.5  3.5";
  std::string line_2 = "4.5  5.5  6.5";
  std::string line_3 = "7.5  8.5  9.5";
  s21::Model model;
  model.ParseLineV(line_1);
  model.ParseLineV(line_2);
  model.ParseLineV(line_3);
  double x = 0.2, y = 0.3, z = 0.4;
  model.Shift(x, y, z);
  EXPECT_NEAR(model.GetVertices()[0].x, 1.7, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].y, 2.8, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].z, 3.9, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].x, 4.7, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].y, 5.8, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].z, 6.9, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].x, 7.7, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].y, 8.8, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].z, 9.9, S21_EPS);
  EXPECT_EQ(model.NumberVertices(), 3);
  EXPECT_EQ(model.GetNumberVertices(), 3);
}

TEST(Scale, Test_1) {
  std::string line_1 = "1.5  2.5  3.5";
  std::string line_2 = "4.5  5.5  6.5";
  std::string line_3 = "7.5  8.5  9.5";
  s21::Model model;
  model.ParseLineV(line_1);
  model.ParseLineV(line_2);
  model.ParseLineV(line_3);
  double scale = 2.0;
  model.Scale(scale);
  EXPECT_NEAR(model.GetVertices()[0].x, 3, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].y, 5, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].z, 7, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].x, 9, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].y, 11, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].z, 13, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].x, 15, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].y, 17, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].z, 19, S21_EPS);
  EXPECT_EQ(model.NumberVertices(), 3);
  EXPECT_EQ(model.GetNumberVertices(), 3);
}

TEST(InitialScale, Test_1) {
  std::string line_1 = "1.5  2.5  3.5";
  std::string line_2 = "4.5  5.5  6.5";
  std::string line_3 = "7.5  8.5  9.5";
  s21::Model model;
  model.ParseLineV(line_1);
  model.ParseLineV(line_2);
  model.ParseLineV(line_3);

  model.InitialScale();
  EXPECT_NEAR(model.GetVertices()[0].x, 0.35, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].y, 0.583333, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].z, 0.816667, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].x, 1.05, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].y, 1.283333, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].z, 1.516667, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].x, 1.75, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].y, 1.983333, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].z, 2.216667, S21_EPS);
}

TEST(InitialScale, Test_2) {
  std::string line_1 = "1.5  2.5  3.5";
  std::string line_2 = "4.5  5.5  6.5";
  std::string line_3 = "7.5  20.5  9.5";
  s21::Model model;
  model.ParseLineV(line_1);
  model.ParseLineV(line_2);
  model.ParseLineV(line_3);

  model.InitialScale();
  EXPECT_NEAR(model.GetVertices()[0].x, 0.116667, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].y, 0.194444, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].z, 0.272222, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].x, 0.35, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].y, 0.427778, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].z, 0.505556, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].x, 0.583333, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].y, 1.594444, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].z, 0.738889, S21_EPS);
}

TEST(Rotate, Test_1) {
  std::string line_1 = "1  2  3";
  std::string line_2 = "4  5  6";
  std::string line_3 = "7  8  9";
  s21::Model model;
  model.ParseLineV(line_1);
  model.ParseLineV(line_2);
  model.ParseLineV(line_3);
  double degrees = 90;

  model.Rotate(degrees, 0);
  EXPECT_NEAR(model.GetVertices()[0].x, 1, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].y, -3, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].z, 2, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].x, 4, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].y, -6, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].z, 5, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].x, 7, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].y, -9, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].z, 8, S21_EPS);
}

TEST(Rotate, Test_2) {
  std::string line_1 = "1  2  3";
  std::string line_2 = "4  5  6";
  std::string line_3 = "7  8  9";
  s21::Model model;
  model.ParseLineV(line_1);
  model.ParseLineV(line_2);
  model.ParseLineV(line_3);
  double degrees = 90;

  model.Rotate(degrees, 1);
  EXPECT_NEAR(model.GetVertices()[0].x, 3, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].y, 2, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].z, -1, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].x, 6, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].y, 5, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].z, -4, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].x, 9, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].y, 8, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].z, -7, S21_EPS);
}

TEST(Rotate, Test_3) {
  std::string line_1 = "1  2  3";
  std::string line_2 = "4  5  6";
  std::string line_3 = "7  8  9";
  s21::Model model;
  model.ParseLineV(line_1);
  model.ParseLineV(line_2);
  model.ParseLineV(line_3);
  double degrees = 90;

  model.Rotate(degrees, 2);
  EXPECT_NEAR(model.GetVertices()[0].x, -2, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].y, 1, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].z, 3, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].x, -5, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].y, 4, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].z, 6, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].x, -8, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].y, 7, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].z, 9, S21_EPS);
}

TEST(CenterVertices, Test_3) {
  std::string line_1 = "1  2  3";
  std::string line_2 = "4  5  6";
  std::string line_3 = "7  8  9";
  s21::Model model;
  model.ParseLineV(line_1);
  model.ParseLineV(line_2);
  model.ParseLineV(line_3);

  model.CenterVertices();
  EXPECT_NEAR(model.GetVertices()[0].x, -3, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].y, -3, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[0].z, -3, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].x, 0, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].y, 0, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[1].z, 0, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].x, 3, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].y, 3, S21_EPS);
  EXPECT_NEAR(model.GetVertices()[2].z, 3, S21_EPS);
}

// Запустите тесты
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}