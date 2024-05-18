
% USO: este código lee los datos de la tabla de salida del ejercicio 3
% "tabla_salida_ej_3.txt" y devuelve una gráfica superponiendo los datos a
% la solución de Onsager.



datos = load(['tabla_salida_ej_3.txt']);

% Extraer las columnas x e y de los datos
x = datos(:, 1);
y = datos(:, 2);

% preparar vectores para Onsager
x_ons = linspace(1.25, 2.25, 100);
y_ons = zeros(size(x_ons));

%calculamos las magnetizaciones dadas por la expresión de Onsager
for i = 1:length(x_ons)
    y_ons(i) = (1- sinh((2*1)/(1*x_ons(i)))^(-4))^(1/8) ;
end


figure;
hold on; 

% Trazar la gráfica
plot(x_ons, y_ons, '-', "Color","b"); % representamos Onsager
plot(x, y, 'o--', "Color","r"); % representamos nuestros datos
xlabel('Temperatura'); 
ylabel('Magnetización');
title(''); 
grid on; 

legend({'Onsager', 'Propios'}, 'Location', 'best');


hold off;


saveas(gcf, 'grafica_ej3.png');