use winit::window::Window;
use std::sync::Arc;
use wgpu;

struct ThyhappyGUIRenderer {
        window: Arc<Window>,
        device: wgpu::Device,
        queue: wgpu::Queue,
        surface: wgpu::Surface<'static>,
        config: wgpu::SurfaceConfiguration,
        size: winit::dpi::PhysicalSize<u32>,
        size_changed: bool,
}

pub fn initialize(){
        todo!()
}

impl ThyhappyGUIRenderer {
        async fn new(window: Arc<Window>) -> Self {
                // Create wgpu instance
                let instance = wgpu::Instance::new(
                        wgpu::InstanceDescriptor {
                                backends: wgpu::Backends::all(),
                                ..Default::default()
                        }
                );

                // Create surface
                let surface = instance.create_surface(window.clone()).unwrap();

                // Create adapter instance
                let adapter = instance.request_adapter(
                        &wgpu::RequestAdapterOptions{
                                power_preference : wgpu::PowerPreference::HighPerformance,
                                compatible_surface : Some(&surface),
                                force_fallback_adapter : false,
                        }
                ).await.unwrap();

                // Create logical devices and commands queue
                let (device, queue) = adapter.request_device(
                        &wgpu::DeviceDescriptor{
                                label: Default::default(),
                                required_features: wgpu::Features::empty(),
                                required_limits: Default::default(),
                        }
                        ,Default::default()
                ).await.unwrap();

                let cap = surface.get_capabilities(&adapter);

                // Set size
                let mut size = window.inner_size();

                // Check if the window size is safe
                size.width  = size.width. max(1);
                size.height = size.height.max(1);

                // Set the configuration
                let config = wgpu::SurfaceConfiguration{
                        usage: wgpu::TextureUsages::RENDER_ATTACHMENT,
                        format: cap.formats[0],
                        width: size.width,
                        height: size.height,
                        present_mode: wgpu::PresentMode::Fifo,
                        desired_maximum_frame_latency: 2,
                        alpha_mode: cap.alpha_modes[0],
                        view_formats: vec![],
                };

                surface.configure(&device, &config);

                Self{
                        window,
                        device,
                        queue,
                        surface,
                        config,
                        size,
                        size_changed: false,
                }
        }

        const BACKGROUND_COLOR: [f32; 3] = [1.0, 1.0, 1.0];

        fn render(&mut self) -> Result<(), wgpu::SurfaceError> {
                // Get a frame object
                let output = self.surface.get_current_texture()?;

                //  Get the surface
                let view = output.texture.create_view(&wgpu::TextureViewDescriptor::default());

                // Create the commands encoder
                let mut encoder = self.device.create_command_encoder(&Default::default());

                // Begin to render
                {
                        let render_pass = encoder.begin_render_pass(
                                &wgpu::RenderPassDescriptor{
                                        // Description of this render pass
                                        label: Some("Render Pass"),
                                        color_attachments: &[
                                                Some(wgpu::RenderPassColorAttachment{
                                                        view: &view,
                                                        resolve_target: None,
                                                        ops: wgpu::Operations{
                                                                // Set background color
                                                                load: wgpu::LoadOp::Clear(wgpu::Color{
                                                                        r: *Self::BACKGROUND_COLOR.get(0).unwrap() as f64,
                                                                        g: *Self::BACKGROUND_COLOR.get(1).unwrap() as f64,
                                                                        b: *Self::BACKGROUND_COLOR.get(2).unwrap() as f64,
                                                                        a: 0.0,
                                                                }),
                                                                store: Default::default(),
                                                        },
                                                })
                                        ],
                                        depth_stencil_attachment: None,
                                        timestamp_writes: None,
                                        occlusion_query_set: None,
                                }
                        );
                }

                // Commit the render commands
                self.queue.submit(Some(encoder.finish()));
                output.present();

                Ok(())
        }
}