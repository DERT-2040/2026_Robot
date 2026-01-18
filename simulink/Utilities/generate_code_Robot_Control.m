function generate_code_Robot_Control()
% generate_controller_code

controllerModel = 'Robot_Control';

if(~bdIsLoaded(controllerModel))
    open_system(controllerModel);
end

% generate code, but do not build
slbuild(controllerModel,'GenerateCodeOnly',true);

% coder.report.generate(controllerModel);

end