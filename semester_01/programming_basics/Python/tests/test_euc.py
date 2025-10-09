import sys, os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "../..")))

from semester_01.programming_basics.Python.src.euclidean_algorithm import EUC, EUC_MOD

def test_euc():
    assert EUC(42,18) == 6
    assert EUC_MOD(18, 42) == 6
    assert EUC_MOD(10, 5) == 5
    assert EUC_MOD(17, 13) == 1
    assert EUC_MOD(0, 9) == 9
    assert EUC_MOD(9, 0) == 9

def test_euc_mod():
    assert EUC_MOD(42, 18) == 6
    assert EUC_MOD(18, 42) == 6
    assert EUC_MOD(10, 5) == 5
    assert EUC_MOD(17, 13) == 1
    assert EUC_MOD(0, 9) == 9
    assert EUC_MOD(9, 0) == 9
