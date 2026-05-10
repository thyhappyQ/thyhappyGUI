use winit;
use winit::event_loop::ControlFlow;
use winit::window::WindowAttributes;

#[derive(Default)]
struct ThyhappyApp {
    window: Option<winit::window::Window>,
}

impl winit::application::ApplicationHandler for ThyhappyApp {
    fn resumed(&mut self, event_loop: &winit::event_loop::ActiveEventLoop) {
        // Check if the window is already created
        if self.window.is_none() {
            // Create window
            self.window = Some(
                event_loop.create_window(
                    WindowAttributes::default()
                        .with_title("hello"))
                    .unwrap()
            )
        }

        // Request redraw window
        if let Some(window) = &self.window {
            window.request_redraw();
        }
    }

    fn window_event(&mut self, event_loop: &winit::event_loop::ActiveEventLoop,
                    id:winit::window::WindowId,event:winit::event::WindowEvent) {
        // Window messages loop
        match event{
            // Do with exiting message
            winit::event::WindowEvent::CloseRequested => {
                event_loop.exit();
            }

            // Do with painting message
            winit::event::WindowEvent::RedrawRequested => {

            }

            // Default
            _=>{}
        }
    }
}

pub fn thyhappy_gui_run() {
    let event_loop = winit::event_loop::EventLoop::new().unwrap();
    let mut app = ThyhappyApp::default();

    event_loop.set_control_flow(ControlFlow::Wait);

    event_loop.run_app(&mut app).unwrap()
}