function generate_code_Odometry()
% generate_controller_code

controllerModel = 'Odometry';

if(~bdIsLoaded(controllerModel))
    open_system(controllerModel);
end

% generate code, but do not build
slbuild(controllerModel,'GenerateCodeOnly',true);

% coder.report.generate(controllerModel);

end