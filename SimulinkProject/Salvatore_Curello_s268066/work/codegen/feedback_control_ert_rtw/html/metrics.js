function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.fcn["ceil"] = {file: "C:\\Program Files\\MATLAB\\R2020b\\polyspace\\verifier\\cxx\\include\\include-libc\\bits\\mathcalls.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["feedback_control_initialize"] = {file: "C:\\Users\\salvo\\MATLAB\\Projects\\Salvatore_Curello_s268066\\work\\codegen\\feedback_control_ert_rtw\\feedback_control.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["feedback_control_step"] = {file: "C:\\Users\\salvo\\MATLAB\\Projects\\Salvatore_Curello_s268066\\work\\codegen\\feedback_control_ert_rtw\\feedback_control.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["feedback_control_terminate"] = {file: "C:\\Users\\salvo\\MATLAB\\Projects\\Salvatore_Curello_s268066\\work\\codegen\\feedback_control_ert_rtw\\feedback_control.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["memset"] = {file: "C:\\Program Files\\MATLAB\\R2020b\\polyspace\\verifier\\cxx\\include\\include-libc\\string.h",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="feedback_control_metrics.html">Global Memory: 0(bytes) Maximum Stack: 4(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
