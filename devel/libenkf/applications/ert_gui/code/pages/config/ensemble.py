
# ----------------------------------------------------------------------------------------------
# Ensemble tab
# ----------------------------------------------------------------------------------------------
from PyQt4 import QtGui, QtCore
from widgets.spinnerwidgets import IntegerSpinner
import ertwrapper
from pages.parameters.parameterpanel import ParameterPanel

def createEnsemblePage(configPanel, parent):

    configPanel.startPage("Ensemble")

    #todo: must have an apply button!!!
    r = configPanel.addRow(IntegerSpinner(parent, "Number of realizations", "num_realizations", 1, 10000))
    r.initialize = lambda ert : [ert.setTypes("enkf_main_get_ensemble_size", ertwrapper.c_int),
                                 ert.setTypes("enkf_main_resize_ensemble", None, [ertwrapper.c_int])]

    r.getter = lambda ert : ert.enkf.enkf_main_get_ensemble_size(ert.main)
    r.setter = lambda ert, value : ert.enkf.enkf_main_resize_ensemble(ert.main, value)

    parent.connect(r, QtCore.SIGNAL("contentsChanged()"), lambda : r.modelEmit("ensembleResized()"))


    #todo: must have an apply button!!!
    configPanel.startGroup("Parameters")
    r = configPanel.addRow(ParameterPanel(parent, "", "parameters"))
    r.getter = lambda ert : ert.getAttribute("summary")
    r.setter = lambda ert, value : ert.setAttribute("summary", value)
    configPanel.endGroup()


    #r = configPanel.addRow(KeywordList(widget, "Summary", "summary"))
    #r.getter = lambda ert : ert.getAttribute("summary")
    #r.setter = lambda ert, value : ert.setAttribute("summary", value)

    #internalPanel = ConfigPanel(widget)
    #
    #internalPanel.startPage("Fields")
    #
    #r = internalPanel.addRow(MultiColumnTable(widget, "Dynamic", "field_dynamic", ["Name", "Min", "Max"]))
    #r.getter = lambda ert : ert.getAttribute("field_dynamic")
    #r.setter = lambda ert, value : ert.setAttribute("field_dynamic", value)
    ##r.setDelegate(1, DoubleSpinBoxDelegate(widget))
    ##r.setDelegate(2, DoubleSpinBoxDelegate(widget))
    #
    #r = internalPanel.addRow(MultiColumnTable(widget, "Parameter", "field_parameter", ["Name", "Min", "Max", "Init", "Output", "Eclipse file", "Init files"]))
    #r.getter = lambda ert : ert.getAttribute("field_parameter")
    #r.setter = lambda ert, value : ert.setAttribute("field_parameter", value)
    #
    #r = internalPanel.addRow(MultiColumnTable(widget, "General", "field_general", ["Name", "Min", "Max", "Init", "Output", "Eclipse file", "Init files", "File generated by EnKF", "File loaded by EnKF"]))
    #r.getter = lambda ert : ert.getAttribute("field_general")
    #r.setter = lambda ert, value : ert.setAttribute("field_general", value)
    #
    #internalPanel.endPage()
    #
    #internalPanel.startPage("Gen")
    #
    #r = internalPanel.addRow(MultiColumnTable(widget, "Keyword", "gen_kw", ["Name", "Template", "Eclipse include", "Priors"]))
    #r.getter = lambda ert : ert.getAttribute("gen_kw")
    #r.setter = lambda ert, value : ert.setAttribute("gen_kw", value)
    #
    #r = internalPanel.addRow(MultiColumnTable(widget, "Data", "gen_data", ["Name", "Result file", "Input", "Output", "Eclipse file", "Init files"]))
    #r.getter = lambda ert : ert.getAttribute("gen_data")
    #r.setter = lambda ert, value : ert.setAttribute("gen_data", value)
    #
    #r = internalPanel.addRow(MultiColumnTable(widget, "Param", "gen_param", ["Name", "Input", "Output", "Eclipse file", "Init files", "Template"]))
    #r.getter = lambda ert : ert.getAttribute("gen_param")
    #r.setter = lambda ert, value : ert.setAttribute("gen_param", value)
    #
    #internalPanel.endPage()
    #configPanel.addRow(internalPanel)

    configPanel.endPage()