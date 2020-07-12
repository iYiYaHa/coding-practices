/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 */

// It's not worth wasting time on this problem.
class Solution {
private:
  map<string, int> parseFormula(string formula) {
    int beg = 0, end = 0;
    map<string, int> res;
    while (end < formula.size()) {
      end = beg + 1;
      map<string, int> subRes; // Result restoring for an element or a
                               // subformula wrapped in parentheses.

      if (formula[beg] == '(') { // subformula
        int left_cnt = 1;
        while (end < formula.size() &&
               left_cnt != 0) { // Find the rightest right parenthese
          if (formula[end] == '(')
            ++left_cnt;
          else if (formula[end] == ')') {
            --left_cnt;
          }
          ++end;
        }
        subRes = parseFormula(
            formula.substr(beg + 1, end - beg - 2)); // Parse the subformula
      } else {
        while (end < formula.size() && !isdigit(formula[end]) &&
               !isupper(formula[end]) &&
               formula[end] !=
                   '(') { // Find the name of the cureent processing element
          ++end;
        }
        subRes.insert({formula.substr(beg, end - beg), 1});
      }

      // Get count(multiplicity) here
      int cnt = 0;
      while (end < formula.size() && isdigit(formula[end])) {
        cnt = cnt * 10 + (formula[end] - '0');
        ++end;
      }
      cnt = cnt == 0 ? 1 : cnt;

      // Merge two map together
      for (auto i = subRes.begin(); i != subRes.end(); ++i) {
        string ele = i->first;
        int ele_cnt = i->second;
        if (res.find(ele) == res.end()) {
          res.insert({ele, ele_cnt * cnt});
        } else {
          res[ele] += ele_cnt * cnt;
        }
      }
      beg = end;
    }
    return res;
  }

public:
  string countOfAtoms(string formula) {
    map<string, int> eleCnt = parseFormula(formula);
    string res;
    for (auto i = eleCnt.begin(); i != eleCnt.end(); ++i) {
      res += (i->first + (i->second == 1 ? "" : to_string(i->second)));
    }
    return res;
  }
};
