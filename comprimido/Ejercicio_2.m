

%USO: este código lee 6 tablas y devuelve una gráfica
%las tablas corresponden a las temperaturas pedidas, los archivos deben ser
%calculados con Ejercicio_2.c y renombrados progresivamente.




tabla1 = readmatrix("1_0.txt");
tabla2 = readmatrix("1_5.txt");
tabla3 = readmatrix("2_0.txt");
tabla4 = readmatrix("2_3.txt");
tabla5 = readmatrix("2_5.txt");
tabla6 = readmatrix("3_0.txt");

% Almacenamos las tablas en una celda
tablas = {tabla1, tabla2, tabla3, tabla4, tabla5, tabla6};


% Tamaño de la figura (en píxeles)
ancho = 1200; % Ancho en píxeles
alto = 800;  % Alto en píxeles

figure('Position', [100, 100, ancho, alto]); % Creamos la figura con el tamaño especificado

colores = {'r', 'g', 'b', 'm', 'c', 'y'};
marcadores = {'o', 's', '^', 'd', 'v', '>'}; % distintos marcadores para cada temperatura 
estilosLinea = {'-', '--', ':', '-.', '-', '--'}; % distintos estilos de línea para cada temperatura 


hold on; % Para superponer las gráficas

% Iteramos sobre cada matriz y traza los puntos en la figura con plot
for i = 1:6
    plot(tablas{i}(:,1), tablas{i}(:,2), 'Color', colores{i}, 'LineStyle', estilosLinea{i}, 'Marker', marcadores{i});
end
xlabel('Pasos'); 
ylabel('Magnetización');

% leyenda
nombres = {'T = 1.0', 'T = 1.5', 'T = 2.0', 'T = 2.3', 'T = 2.5', 'T = 3.0'};
legend(nombres, 'Location', 'best');

hold off; % Para evitar que se superpongan más gráficos

saveas(gcf, 'grafica_ej2.png'); % Guardamos la figura
