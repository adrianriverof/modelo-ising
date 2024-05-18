
%USO: este código lee 6 tablas y devuelve una gráfica
%las tablas corresponden a las temperaturas pedidas, los archivos deben ser
%progresivamente calculados con Ejercicio_2.c y renombrados
%progresivamente.




tabla1 = readmatrix("1_0.txt");
tabla2 = readmatrix("1_5.txt");
tabla3 = readmatrix("2_0.txt");
tabla4 = readmatrix("2_3.txt");
tabla5 = readmatrix("2_5.txt");
tabla6 = readmatrix("3_0.txt");

% Almacena las tablas en una celda
tablas = {tabla1, tabla2, tabla3, tabla4, tabla5, tabla6};


figure;
colores = {'r', 'g', 'b', 'm', 'c', 'y'};

hold on; % Para superponer las gráficas

% Itera sobre cada matriz y traza los puntos en la figura con plot
for i = 1:6
    plot(tablas{i}(:,1), tablas{i}(:,2), '-', 'Color', colores{i}); % plot para trazar puntos
end
xlabel('Pasos'); 
ylabel('Magnetización');
% leyenda
nombres = {'T = 1.0', 'T = 1.5', 'T = 2.0', 'T = 2.3', 'T = 2.5', 'T = 3.0'};
legend(nombres, 'Location', 'best');

hold off; % Para evitar que se superpongan más gráficos

saveas(gcf, 'grafica_ej2.png'); % Guarda la figura