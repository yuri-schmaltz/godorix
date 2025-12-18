# Checklist de Acessibilidade para Controles

Este documento fornece diretrizes para garantir que todos os controles do Godot Editor atendam aos padrões WCAG 2.1 AA de acessibilidade.

## Requisitos Obrigatórios

### 1. Nome Acessível (Accessibility Name)
- [ ] Todo `Control` deve ter um `accessibility_name` definido
- [ ] O nome deve descrever claramente a função do controle
- [ ] Use `set_accessibility_name(TTRC("Nome do Controle"))` para suporte a tradução

**Exemplo:**
```cpp
Button *my_button = memnew(Button);
my_button->set_accessibility_name(TTRC("Save File"));
```

### 2. Descrição Acessível (Accessibility Description)
- [ ] Controles complexos devem ter uma `accessibility_description`
- [ ] A descrição deve fornecer contexto adicional quando necessário
- [ ] Use para explicar o propósito ou resultado da ação

**Exemplo:**
```cpp
button->set_accessibility_description(TTRC("Saves the current file to disk"));
```

### 3. Role Semântico (ARIA Role)
- [ ] Defina o role apropriado para controles customizados
- [ ] Use `DisplayServer::accessibility_update_set_role()` em `NOTIFICATION_ACCESSIBILITY_UPDATE`

**Exemplo:**
```cpp
void _notification(int p_what) {
    switch (p_what) {
        case NOTIFICATION_ACCESSIBILITY_UPDATE: {
            RID ae = get_accessibility_element();
            DisplayServer::get_singleton()->accessibility_update_set_role(ae, 
                DisplayServer::AccessibilityRole::ROLE_BUTTON);
        } break;
    }
}
```

### 4. Navegação por Teclado
- [ ] Todos os controles interativos devem ser acessíveis via teclado
- [ ] Implemente navegação por Tab (focus_next/focus_previous)
- [ ] Suporte teclas de atalho padrão (Enter, Espaço, Esc, setas)
- [ ] Configure `set_focus_mode(FOCUS_ALL)` para controles interativos

**Exemplo:**
```cpp
control->set_focus_mode(Control::FOCUS_ALL);
control->set_focus_next(next_control->get_path());
control->set_focus_previous(prev_control->get_path());
```

### 5. Indicador de Foco Visível
- [ ] Foco deve ser visualmente claro (borda, outline, etc.)
- [ ] Contraste mínimo de 3:1 entre foco e fundo
- [ ] Use estilos de tema para consistência

**Verificação:**
```cpp
// Garantir que o tema tem estilo de foco
Ref<StyleBox> focus_style = get_theme_stylebox("focus", "Button");
```

### 6. Contraste de Cores
- [ ] Texto normal: contraste mínimo 4.5:1
- [ ] Texto grande (18pt+ ou 14pt+ bold): contraste mínimo 3:1
- [ ] Elementos gráficos importantes: contraste mínimo 3:1

**Ferramentas:**
- Use `misc/scripts/check_color_contrast.py` (quando disponível)
- Teste com WebAIM Contrast Checker

### 7. Tamanhos de Alvo (Touch Targets)
- [ ] Controles interativos devem ter mínimo 44x44 pixels (WCAG 2.1 AAA)
- [ ] Recomendado 48x48 pixels para melhor usabilidade
- [ ] Configure `custom_minimum_size` quando necessário

**Exemplo:**
```cpp
button->set_custom_minimum_size(Size2(48, 48));
```

### 8. Estados e Feedback
- [ ] Estados devem ser comunicados visualmente E via acessibilidade
- [ ] Implemente estados: normal, hover, pressed, disabled, focused
- [ ] Use `accessibility_update_set_value()` para estados dinâmicos

**Exemplo:**
```cpp
void set_checked(bool p_checked) {
    checked = p_checked;
    RID ae = get_accessibility_element();
    DisplayServer::get_singleton()->accessibility_update_set_value(ae, 
        p_checked ? "checked" : "unchecked");
}
```

### 9. Mensagens de Erro e Validação
- [ ] Erros devem ser anunciados para screen readers
- [ ] Use `accessibility_update_set_description()` para mensagens dinâmicas
- [ ] Forneça instruções claras para correção

### 10. Suporte a Screen Readers
- [ ] Teste com NVDA (Windows), ORCA (Linux), VoiceOver (macOS)
- [ ] Garanta que a ordem de leitura seja lógica
- [ ] Evite texto em imagens (ou forneça texto alternativo)

## Checklist de PR

Ao criar um novo controle ou modificar um existente, verifique:

- [ ] **Acessibilidade**: Nome e descrição definidos
- [ ] **Teclado**: Navegação funciona corretamente
- [ ] **Foco**: Indicador visível e com contraste adequado
- [ ] **Cores**: Contraste mínimo atendido (4.5:1 texto, 3:1 UI)
- [ ] **Tamanhos**: Alvos têm mínimo 44x44px
- [ ] **Estados**: Todos os estados têm feedback visual e acessível
- [ ] **Screen Reader**: Testado com leitor de tela
- [ ] **Documentação**: Atualizei a documentação se necessário

## Exemplos Completos

### Controle Simples (Button)
```cpp
Button *action_button = memnew(Button);
action_button->set_text(TTR("Execute"));
action_button->set_accessibility_name(TTRC("Execute Action"));
action_button->set_accessibility_description(TTRC("Executes the current action"));
action_button->set_focus_mode(Control::FOCUS_ALL);
action_button->set_custom_minimum_size(Size2(48, 48));
```

### Controle Complexo (Custom Widget)
```cpp
class MyCustomWidget : public Control {
    GDCLASS(MyCustomWidget, Control);
    
protected:
    void _notification(int p_what) {
        switch (p_what) {
            case NOTIFICATION_ACCESSIBILITY_UPDATE: {
                RID ae = get_accessibility_element();
                DisplayServer::get_singleton()->accessibility_update_set_role(ae, 
                    DisplayServer::AccessibilityRole::ROLE_STATIC_TEXT);
                DisplayServer::get_singleton()->accessibility_update_set_value(ae, 
                    get_current_value());
            } break;
        }
    }
    
public:
    MyCustomWidget() {
        set_accessibility_name(TTRC("Custom Widget"));
        set_focus_mode(FOCUS_ALL);
    }
};
```

## Recursos Adicionais

- WCAG 2.1 Guidelines: https://www.w3.org/WAI/WCAG21/quickref/
- Godot Accessibility API: `scene/gui/control.h`
- DisplayServer Accessibility: `servers/display_server.h`

## Contato

Para dúvidas sobre acessibilidade, abra uma issue no GitHub com a tag `accessibility`.
