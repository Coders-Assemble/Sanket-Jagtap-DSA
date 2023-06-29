#include <iostream>
using namespace std;

int main() {
  // Solid Rectangle
  // for (int row = 0; row < 3; row++) {
  //   for (int row = 0; row < 5; row++) {
  //     cout << "* ";
  //   }
  //   cout << endl;
  // }

  // Solid Square
  // int n;
  // cin >> n;
  // for (int row = 0; row < n; row++) {
  //   for (int col = 0; col < n; col++) {
  //     cout << "* ";
  //   }
  //   cout << endl;
  // }

  // Hollow Rectangle
  // int rowCount, colCount;
  // cin >> rowCount;
  // cin >> colCount;

  // for (int row = 0; row < rowCount; row++) {
  //   if (row == 0 || row == rowCount - 1) {
  //     for (int col = 0; col < colCount; col++) {
  //       cout << "* ";
  //     }
  //   } else {
  //     cout << "* ";
  //     for (int col = 0; col < colCount - 2; col++) {
  //       cout << "  ";
  //     }
  //     cout << "* ";
  //   }
  //   cout << endl;
  // }

  // Hollow Square
  // int n;
  // cin >> n;

  // for (int row = 0; row < n; row++) {
  //   if (row == 0 || row == n - 1) {
  //     for (int col = 0; col < n; col++) {
  //       cout << "* ";
  //     }
  //   } else {
  //     cout << "* ";
  //     for (int col = 0; col < n - 2; col++) {
  //       cout << "  ";
  //     }
  //     cout << "*";
  //   }
  //   cout << endl;
  // }

  // Half Pyramid
  // int n;
  // cin >> n;

  // for (int row = 0; row < n; row++) {
  //   for (int col = 0; col < row + 1; col++) {
  //     cout << "* ";
  //   }
  //   cout << endl;
  // }

  // Inverted Half Pyramid
  // int n;
  // cin >> n;

  // for (int row = 0; row < n; row++) {
  //   for (int col = 0; col < n-row; col++) {
  //     cout << "* ";
  //   }
  //   cout << endl;
  // }

  // Hollow Inverted Half Pyramid
  // int n;
  // cin >> n;

  // for (int row = 0; row < n; row++) {
  //   if (row == 0 || row == n - 1) {
  //     for (int col = 0; col < n - row; col++) {
  //       cout << "* ";
  //     }
  //   } else {
  //     cout << "* ";
  //     for (int col = 0; col < n - row - 2; col++) {
  //       cout << "  ";
  //     }
  //     cout << "*";
  //   }
  //   cout << endl;
  // }

  // Numeric Half Pyramid
  // int n;
  // cin >> n;

  // for (int row = 0; row < n; row++) {
  //   for (int col = 0; col < row + 1; col++) {
  //     cout << col+1<<" ";
  //   }
  //   cout << endl;
  // }

  // Numeric Hollow Half Pyramid
  // int n;
  // cin >> n;

  // for (int row = 0; row < n; row++) {
  //   if (row == 0 || row == n - 1) {
  //     for (int col = 0; col < row + 1; col++) {
  //       cout << col+1 << " ";
  //     }
  //   } else {
  //     cout << "1 ";
  //     int col;
  //     for (col = 0; col < row - 1; col++) {
  //       cout << "  ";
  //     }
  //     cout << col+2;
  //   }
  //   cout << endl;
  // }

  // Numeric Hollow Inverted Half Pyramid
  // int n;
  // cin >> n;

  // for (int row = 0; row < n; row++) {
  //   for (int col = 0; col < n - row; col++) {
  //     if (row == 0 || row == n - 1) {
  //       cout << row + col + 1<<" ";
  //     } else if (col == 0 || col == n - row - 1) {
  //       cout << row + col + 1<<" ";
  //     } else {
  //       cout << "  ";
  //     }
  //   }
  //   cout << endl;
  // }

  // Inverted Half Pyramid
  // int n;
  // cin >> n;

  // for (int row = 0; row < n; row++) {
  //   for (int col = 0; col < n - row; col++) {
  //     cout << col + 1 << " ";
  //   }
  //   cout << endl;
  // }

  // Full Pyramid
  /*
  int n;
  cin >> n;

  // Method 1
  for (int row = 0; row < n; row++) {
    // Spaces
    for (int col = 0; col < n - row - 1; col++) {
      cout << " ";
    }
    // Stars
    for (int col = 0; col < row + 1; col++) {
      cout << "* ";
    }
    cout << endl;
  }

    // Method 2
    for (int row = 0; row < n; row++) {
      // Spaces
      for (int col = 0; col < n - row - 1; col++) {
        cout << " ";
      }
      // Stars
      for (int col = 0; col < 2 * row + 1; col++) {
        if (col % 2 == 0) {
          cout << "*";
        } else {
          cout << " ";
        }
      }
      cout << endl;
    }
    */

  // Hollow Full Pyramid
  // int n;
  // cin >> n;

  // for (int row = 0; row < n; row++) {
  //   for (int col = 0; col < n - row - 1; col++) {
  //     cout << " ";
  //   }

  //   if (row == 0 || row == n - 1) {
  //     for (int col = 0; col < row + 1; col++) {
  //       cout << "* ";
  //     }
  //   } else {
  //     cout << "* ";
  //     for (int col = 0; col < row - 1; col++) {
  //       cout << "  ";
  //     }
  //     cout << "*";
  //   }
  //   cout << endl;
  // }

  // Inverted Full Pyramid
  /*
  int n;
  cin >> n;

  // Method 1
  for (int row = 0; row < n; row++) {
    // Spaces
    for (int col = 0; col < row; col++) {
      cout << " ";
    }
    // Stars
    for (int col = 0; col < n - row; col++) {
      cout << "* ";
    }
    cout << endl;
  }

  // Method 2
  for (int row = 0; row < n; row++) {
    // Spaces
    for (int col = 0; col < row; col++) {
      cout << " ";
    }
    // Stars
    for (int col = 0; col < 2 * (n - row) - 1; col++) {
      if (col % 2 == 0) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
  */

  // Solid Half Diamond

  int n;
  cin >> n;

  for (int row = 0; row < n; row++) {
    for (int col = 0; col < 2 * row + 1; col++) {
      if (col % 2 == 0) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
  for (int row = 1; row < n; row++) {
    for (int col = 0; col < 2 * (n - row) - 1; col++) {
      if (col % 2 == 0) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }

  // Solid Diamond
  /*
  int n;
  cin >> n;

  // Method 1
  for (int row = 0; row < n; row++) {
    // Spaces
    for (int col = 0; col < n - row - 1; col++) {
      cout << " ";
    }
    // Stars
    for (int col = 0; col < row + 1; col++) {
      cout << "* ";
    }
    cout << endl;
  }

  for (int row = 0; row < n; row++) {
    // Spaces
    for (int col = 0; col < row; col++) {
      cout << " ";
    }
    // Stars
    for (int col = 0; col < n - row; col++) {
      cout << "* ";
    }
    cout << endl;
  }

  // Method 2
  for (int row = 0; row < n; row++) {
    // Spaces
    for (int col = 0; col < n - row - 1; col++) {
      cout << " ";
    }
    // Stars
    for (int col = 0; col < 2 * row + 1; col++) {
      if (col % 2 == 0) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }

  for (int row = 0; row < n; row++) {
    // Spaces
    for (int col = 0; col < row; col++) {
      cout << " ";
    }
    // Stars
    for (int col = 0; col < 2 * (n - row) - 1; col++) {
      if (col % 2 == 0) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
  */

  // Hollow diamond
  /*
  int n;
  cin >> n;
  for (int row = 0; row < n; row++) {
    // Spaces
    for (int col = 0; col < n - row - 1; col++) {
      cout << " ";
    }
    // Stars
    for (int col = 0; col < 2 * row + 1; col++) {
      if (col == 0) {
        cout << "*";
      } else if (col == 2 * row) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }

  for (int row = 0; row < n; row++) {
    // Spaces
    for (int col = 0; col < row; col++) {
      cout << " ";
    }
    // Stars
    for (int col = 0; col < 2 * (n - row) - 1; col++) {
      if (col == 0) {
        cout << "*";
      } else if (col == 2 * (n - row) - 2) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
  */

  // Flipped solid diamond
  /*
  int n;
  cin >> n;

  for (int row = 0; row < n; row++) {
    // Half Pyramid
    for (int col = 0; col < n - row; col++) {
      cout << "*";
    }

    // Spaces pyramid
    for (int col = 0; col < 2 * row + 1; col++) {
      cout << " ";
    }

    // Half Pyramid
    for (int col = 0; col < n - row; col++) {
      cout << "*";
    }
    cout << endl;
  }

  for (int row = 0; row < n; row++) {
    // Half Pyramid
    for (int col = 0; col < row + 1; col++) {
      cout << "*";
    }

    // Spaces pyramid
    for (int col = 0; col < 2 * (n - row) - 1; col++) {
      cout << " ";
    }

    // Half Pyramid
    for (int col = 0; col < row + 1; col++) {
      cout << "*";
    }
    cout << endl;
  }
  */

  // Fancy Pattern
  // int n;
  // cin >> n;

  // for (int row = 0; row < n; row++) {
  //   for (int col = 0; col < row + 1; col++) {
  //     cout << row + 1;
  //     if (col != row) {
  //       cout << "*";
  //     }
  //   }
  //   cout << endl;
  // }
  // for (int row = 0; row < n; row++) {
  //   for (int col = 0; col < n - row; col++) {
  //     cout << n - row;
  //     if (col != n - row - 1) {
  //       cout << "*";
  //     }
  //   }
  //   cout << endl;
  // }

  // Alphabet Palindrome Pyramid
  // int n;
  // cin >> n;

  // for (int row = 0; row < n; row++) {
  //   for (int col = 0; col < row + 1; col++) {
  //     int ans = col + 1;
  //     char ch = ans + 'A' - 1;
  //     cout << ch;
  //   }

  //   for (int col = row; col >= 1; col--) {
  //     int ans = col;
  //     char ch = ans + 'A' - 1;
  //     cout << ch;
  //   }
  //   cout << endl;
  // }

  // Numeric palindrome full pyramid
  // int n;
  // cin >> n;

  // for (int row = 0; row < n; row++) {
  //   // Spaces
  //   for (int col = 0; col < n - row - 1; col++) {
  //     cout << "  ";
  //   }

  //   // Numbers
  //   for (int col = 0; col < row + 1; col++) {
  //     cout << row + col + 1<<" ";
  //   }

  //   // Reverse Counting
  //   int start = 2 * row;
  //   for (int col = 0; col < row; col++) {
  //     cout << start<<" ";
  //     start--;
  //   }
  //   cout << endl;
  // }

  // Numeric Hollow Full Pyramid
  /* int n;
  cin >> n;

  for (int row = 0; row < n; row++) {
    // Spaces
    for (int col = 0; col < n - row - 1; col++) {
      cout << " ";
    }

    int start = 1;
    for (int col = 0; col < 2 * row + 1; col++) {
      if (row == 0 || row == n - 1) {
        if (col % 2 == 0) {
          cout << start;
          start++;
        } else {
          cout << " ";
        }
      } else {
        if (col == 0) {
          cout << col + 1;
        } else if (col == 2 * row) {
          cout << row + 1;
        } else {
          cout << " ";
        }
      }
    }
    cout << endl;
  }*/

  return 0;
}